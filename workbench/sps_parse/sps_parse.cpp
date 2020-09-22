#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

uint32_t Ue(uint8_t *pBuff, uint32_t nLen, uint32_t &nStartBit)
{
    uint32_t nZeroNum = 0;
    while (nStartBit < nLen * 8)
    {
        if (pBuff[nStartBit / 8] & (0x80 >> (nStartBit % 8)))
        {
            break;
        }
        nZeroNum++;
        nStartBit++;
    }
    nStartBit++;

    uint32_t dwRet = 0;
    for (uint32_t i = 0; i < nZeroNum; i++)
    {
        dwRet <<= 1;
        if (pBuff[nStartBit / 8] & (0x80 >> (nStartBit % 8)))
        {
            dwRet += 1;
        }
        nStartBit++;
    }
    return (1 << nZeroNum) - 1 + dwRet;
}

int32_t Se(uint8_t *pBuff, uint32_t nLen, uint32_t &nStartBit)
{
    uint32_t UeVal = Ue(pBuff, nLen, nStartBit);
    if (UeVal & 0x01)
    {
        return (UeVal + 1) / 2;
    }
    else
    {
        return -(UeVal / 2);
    }
}

uint32_t u(uint32_t BitCount, uint8_t *buf, uint32_t &nStartBit)
{
    uint32_t dwRet = 0;
    for (uint32_t i = 0; i < BitCount; i++)
    {
        dwRet <<= 1;
        if (buf[nStartBit / 8] & (0x80 >> (nStartBit % 8)))
        {
            dwRet += 1;
        }
        nStartBit++;
    }
    return dwRet;
}

void de_emulation_prevention(uint8_t *buf, uint32_t &buf_size)
{
    uint8_t *tmp_ptr = buf;
    unsigned int tmp_buf_size = buf_size;

    for (uint32_t i = 0; i < (tmp_buf_size - 2); i++)
    {
        //check for 0x000003
        if (((tmp_ptr[i] ^ 0x00) + (tmp_ptr[i + 1] ^ 0x00) + (tmp_ptr[i + 2] ^ 0x03)) == 0)
        {
            //kick out 0x03
            for (uint32_t j = i + 2; j < tmp_buf_size - 1; j++)
                tmp_ptr[j] = tmp_ptr[j + 1];

            //and so we should decrease bufsize
            (buf_size)--;
        }
    }
}

// Reference to ISO/IEC 14496-10-2012 7.3.2.1.1 Sequence parameter set data syntax
bool h264_decode_sps(uint8_t *buf, uint32_t nLen, int &width, int &height, int &fps)
{
    uint32_t StartBit = 0;
    fps = 0;
    de_emulation_prevention(buf, nLen);

    int timing_info_present_flag = 0;
    int forbidden_zero_bit = u(1, buf, StartBit);
    int nal_ref_idc = u(2, buf, StartBit);
    int nal_unit_type = u(5, buf, StartBit);
    if (nal_unit_type == 7)
    {
        int profile_idc = u(8, buf, StartBit);
        int constraint_set0_flag = u(1, buf, StartBit);
        int constraint_set1_flag = u(1, buf, StartBit);
        int constraint_set2_flag = u(1, buf, StartBit);
        int constraint_set3_flag = u(1, buf, StartBit);
        int constraint_set4_flag = u(1, buf, StartBit);
        int constraint_set5_flag = u(1, buf, StartBit);
        int reserved_zero_2bits = u(2, buf, StartBit);
        int level_idc = u(8, buf, StartBit);

        int seq_parameter_set_id = Ue(buf, nLen, StartBit);
        if (profile_idc == 100 || profile_idc == 110 || profile_idc == 122 ||
            profile_idc == 244 || profile_idc == 44 || profile_idc == 83 ||
            profile_idc == 86 || profile_idc == 118 || profile_idc == 128)
        {
            int chroma_format_idc = Ue(buf, nLen, StartBit);
            if (chroma_format_idc == 3)
                int residual_colour_transform_flag = u(1, buf, StartBit);
            int bit_depth_luma_minus8 = Ue(buf, nLen, StartBit);
            int bit_depth_chroma_minus8 = Ue(buf, nLen, StartBit);
            int qpprime_y_zero_transform_bypass_flag = u(1, buf, StartBit);
            int seq_scaling_matrix_present_flag = u(1, buf, StartBit);

            int seq_scaling_list_present_flag[12];
            if (seq_scaling_matrix_present_flag)
            {
                for (int i = 0; i < ((chroma_format_idc != 3) ? 8 : 12); i++)
                {
                    seq_scaling_list_present_flag[i] = u(1, buf, StartBit);
                }
            }
        }
        int log2_max_frame_num_minus4 = Ue(buf, nLen, StartBit);
        int pic_order_cnt_type = Ue(buf, nLen, StartBit);
        if (pic_order_cnt_type == 0)
            int log2_max_pic_order_cnt_lsb_minus4 = Ue(buf, nLen, StartBit);
        else if (pic_order_cnt_type == 1)
        {
            int delta_pic_order_always_zero_flag = u(1, buf, StartBit);
            int offset_for_non_ref_pic = Se(buf, nLen, StartBit);
            int offset_for_top_to_bottom_field = Se(buf, nLen, StartBit);
            int num_ref_frames_in_pic_order_cnt_cycle = Ue(buf, nLen, StartBit);

            int *offset_for_ref_frame = new int[num_ref_frames_in_pic_order_cnt_cycle];
            for (int i = 0; i < num_ref_frames_in_pic_order_cnt_cycle; i++)
                offset_for_ref_frame[i] = Se(buf, nLen, StartBit);
            delete[] offset_for_ref_frame;
        }
        int num_ref_frames = Ue(buf, nLen, StartBit);
        int gaps_in_frame_num_value_allowed_flag = u(1, buf, StartBit);
        int pic_width_in_mbs_minus1 = Ue(buf, nLen, StartBit);
        int pic_height_in_map_units_minus1 = Ue(buf, nLen, StartBit);
        int frame_mbs_only_flag = u(1, buf, StartBit);
        if (!frame_mbs_only_flag)
            int mb_adaptive_frame_field_flag = u(1, buf, StartBit);

        int direct_8x8_inference_flag = u(1, buf, StartBit);

        width = (pic_width_in_mbs_minus1 + 1) * 16;
        height = (2 - frame_mbs_only_flag) * (pic_height_in_map_units_minus1 + 1) * 16;

        int frame_cropping_flag = u(1, buf, StartBit);
        if (frame_cropping_flag)
        {
            int frame_crop_left_offset = Ue(buf, nLen, StartBit);
            int frame_crop_right_offset = Ue(buf, nLen, StartBit);
            int frame_crop_top_offset = Ue(buf, nLen, StartBit);
            int frame_crop_bottom_offset = Ue(buf, nLen, StartBit);

            width = width - (frame_crop_bottom_offset * 2) - (frame_crop_top_offset * 2);
            height = height - (frame_crop_bottom_offset * 2) - (frame_crop_top_offset * 2);
        }

        int vui_parameter_present_flag = u(1, buf, StartBit);
        if (vui_parameter_present_flag)
        {
            int aspect_ratio_info_present_flag = u(1, buf, StartBit);
            if (aspect_ratio_info_present_flag)
            {
                int aspect_ratio_idc = u(8, buf, StartBit);
                if (aspect_ratio_idc == 255)
                {
                    int sar_width = u(16, buf, StartBit);
                    int sar_height = u(16, buf, StartBit);
                }
            }
            int overscan_info_present_flag = u(1, buf, StartBit);
            if (overscan_info_present_flag)
                int overscan_appropriate_flagu = u(1, buf, StartBit);
            int video_signal_type_present_flag = u(1, buf, StartBit);
            if (video_signal_type_present_flag)
            {
                int video_format = u(3, buf, StartBit);
                int video_full_range_flag = u(1, buf, StartBit);
                int colour_description_present_flag = u(1, buf, StartBit);
                if (colour_description_present_flag)
                {
                    int colour_primaries = u(8, buf, StartBit);
                    int transfer_characteristics = u(8, buf, StartBit);
                    int matrix_coefficients = u(8, buf, StartBit);
                }
            }
            int chroma_loc_info_present_flag = u(1, buf, StartBit);
            if (chroma_loc_info_present_flag)
            {
                int chroma_sample_loc_type_top_field = Ue(buf, nLen, StartBit);
                int chroma_sample_loc_type_bottom_field = Ue(buf, nLen, StartBit);
            }
            timing_info_present_flag = u(1, buf, StartBit);

            if (timing_info_present_flag)
            {
                int num_units_in_tick = u(32, buf, StartBit);
                int time_scale = u(32, buf, StartBit);
                fps = time_scale / num_units_in_tick;
                int fixed_frame_rate_flag = u(1, buf, StartBit);
                if (fixed_frame_rate_flag)
                {
                    fps = fps / 2;
                }
            }
        }

        if (timing_info_present_flag)
        {
            printf("H.264 SPS: -> video size %dx%d, %d fps, profile(%02x)\n",
                   width, height, fps, profile_idc);
        }
        else
        {
            printf("H.264 SPS: -> video size %dx%d, unknown fps, profile(%02x)\n",
                   width, height, profile_idc);
        }

        return true;
    }
    else
        return false;
}

int main()
{
    uint8_t buf[15] = {0x67, 0x42, 0xc0, 0x1f, 0x08, 0x0c, 0x8d, 0x40, 0x50, 0x1e, 0x90, 0x0f, 0x08, 0x84, 0x6a};
    // uint8_t buf[27] = {0x67, 0x64, 0x00, 0x1e, 0xac, 0xd3, 0x05, 0xc1, 0x47, 0x97, 0x9b, 0x81, 0x01, 0x02, 0xa0, 0x00, 0x00, 0x03, 0x00, 0x20, 0x00, 0x00, 0x06, 0x11, 0xe2, 0xc5, 0xa7};
    int w = 0, h = 0, fps = 0;

    bool ret = h264_decode_sps(&buf[0], 27, w, h, fps);
    if (ret == false)
        printf("decode error...\n");
}
