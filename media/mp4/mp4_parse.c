
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define BOX_FTYP 0x66747970
#define MDAT_BOX 0x6D646174
#define MOOV_BOX 0x6D6F6F76
#define MVHD_BOX 0x6D766864
#define TRAK_BOX 0x7472616B
#define IODS_BOX 0x696F6473
#define UDTA_BOX 0x75647461
#define FREE_BOX 0x66726565
#define TKHD_BOX 0x746B6864
#define MDIA_BOX 0x6D646961
#define MDHD_BOX 0x6D646864
#define HDLR_BOX 0x68646C72
#define MINF_BOX 0x6D696E66
#define DINF_BOX 0x64696E66
#define TREF_BOX 0x74726566
#define STBL_BOX 0x7374626C
#define STSD_BOX 0x73747364
#define MP4S_BOX 0x6D703473
#define ESDS_BOX 0x65736473
#define STTS_BOX 0x73747473
#define STSC_BOX 0x73747363
#define STSZ_BOX 0x7374737A
#define STCO_BOX 0x7374636F
#define STSS_BOX 0x73747373
#define CTTS_BOX 0x63747473
#define EDTS_BOX 0x65647473
#define VMHD_BOX 0x766D6864
#define HMHD_BOX 0x686D6864
#define SMHD_BOX 0x736D6864
#define NMHD_BOX 0xffffffff

#define ODSM    0x6F64736D
#define SDSM    0x7364736D
#define VIDE    0x76696465
#define HINT    0x68696E74
#define SOUN    0x736F756E

typedef struct BOX_HEAD
{
    unsigned int size;
    unsigned int type;
}BOX_HEAD;

typedef struct FTYP_BOX
{
    unsigned int ftyp_size;
    unsigned int ftyp_type;
}FTYP_BOX;


typedef struct MOOV_HEADER_BOX
{
    unsigned int create_time;
    unsigned int modification_time;
    unsigned int time_scale;
    unsigned int duration;
    unsigned int preferred_rate;
    unsigned short preferred_volume;
    char reserved[10];
    char matrix_structure[36];
    char pre_defined[24];
    unsigned int next_track_id;
}MOOV_HEADER_BOX;

typedef struct Track_head_box
{
    unsigned int create_time;
    unsigned int modification_time;
    unsigned int track_id;
    unsigned int reserved1;
    unsigned int duration;
    unsigned int reserved2[2];
    unsigned short layer;
    unsigned short alternate_group;
    unsigned short volume;
    unsigned short reserved3;
    char matrix[36];
    unsigned int width;
    unsigned int height;
}TRACK_HEAD_BOX;

typedef struct Mdhd_head_box
{
    unsigned int create_time;
    unsigned int modification_time;
    unsigned int time_scale;
    unsigned int duration;
    unsigned short language;
    unsigned short quality;
}MDHD_HEAD_BOX;

typedef struct Ret_Boxhead_Fileptr
{
    BOX_HEAD box_head;
    FILE *p;
}Ret_Boxhead_Fileptr;

struct MP4_INFO
{
    unsigned int create_time;
    unsigned int modification_time;
}mp4_info;

unsigned int big_to_small_endian_32bit(unsigned int const big)
{
    unsigned int data = big;
    unsigned int ret = 0;
    ret += (data>>0 & 0xff) << 24;
    ret += (data>>8 & 0xff) << 16;
    ret += (data>>16 & 0xff) << 8;
    ret += (data>>24 & 0xff) << 0;
    return ret;
}

int64_t big_to_small_endian_64bit(int64_t const big)
{
    int64_t data = big;
    int64_t ret = 0;
    ret += (data>>0 & 0xff) << 56;
    ret += (data>>8 & 0xff) << 48;
    ret += (data>>16 & 0xff) << 40;
    ret += (data>>24 & 0xff) << 32;
    ret += (data>>32 & 0xff) << 24;
    ret += (data>>40 & 0xff) << 16;
    ret += (data>>48 & 0xff) << 8;
    ret += (data>>56 & 0xff) << 0;
    return ret;
}

void print_box_type(unsigned int box_type, unsigned int num)
{
    for(unsigned int i = 0; i < num; i++)
    {
        printf("\t");
    }
    switch(big_to_small_endian_32bit(box_type))
    {
        case BOX_FTYP:
        {
            printf("%s\n", "ftyp box");
        }
        break;

        case MOOV_BOX:
        {
            printf("%s\n", "moov box");
        }
        break;

        case MDAT_BOX:
        {
            printf("%s\n", "mdat box");
        }
        break;

        case MVHD_BOX:
        {
            printf("%s\n", "mvhd box");
        }
        break;

        case IODS_BOX:
        {
            printf("%s\n", "iods box");
        }
        break;

        case UDTA_BOX:
        {
            printf("%s\n", "udta box");
        }
        break;

        case TRAK_BOX:
        {
            printf("%s\n", "trak box");
        }
        break;

        case TKHD_BOX:
        {
            printf("%s\n", "tkhd box");
        }
        break;

        case MDIA_BOX:
        {
            printf("%s\n", "mdia box");
        }
        break;

        case MDHD_BOX:
        {
            printf("%s\n", "mdhd box");
        }
        break;

        case HDLR_BOX:
        {
            printf("%s\n", "hdlr box");
        }
        break;

        case MINF_BOX:
        {
            printf("%s\n", "minf box");
        }
        break;

        case DINF_BOX:
        {
            printf("%s\n", "dinf box");
        }
        break;

        case TREF_BOX:
        {
            printf("%s\n", "tref box");
        }
        break;

        case STBL_BOX:
        {
            printf("%s\n", "stbl box");
        }
        break;

        case STSD_BOX:
        {
            printf("%s\n", "stsd box");
        }
        break;

        case MP4S_BOX:
        {
            printf("%s\n", "mp4s box");
        }
        break;

        case ESDS_BOX:
        {
            printf("%s\n", "esds box");
        }
        break;

        case STTS_BOX:
        {
            printf("%s\n", "stts box");
        }
        break;

        case STSC_BOX:
        {
            printf("%s\n", "stsc box");
        }
        break;

        case STSZ_BOX:
        {
            printf("%s\n", "stsz box");
        }
        break;

        case STCO_BOX:
        {
            printf("%s\n", "stco box");
        }
        break;

        case STSS_BOX:
        {
            printf("%s\n", "stss box");
        }
        break;

        case CTTS_BOX:
        {
            printf("%s\n", "ctts box");
        }
        break;

        case EDTS_BOX:
        {
            printf("%s\n", "edts box");
        }
        break;

        case VMHD_BOX:
        {
            printf("%s\n", "vmhd box");
        }
        break;

        case SMHD_BOX:
        {
            printf("%s\n", "smhd box");
        }
        break;

        case HMHD_BOX:
        {
            printf("%s\n", "hmhd box");
        }
        break;

        case NMHD_BOX:
        {
            printf("%s\n", "nmhd box");
        }
        break;
    }
}

enum timeType
{
    CREATE_TIME,
    MODIFY_TIME
};

void create_and_modify_time(unsigned int time, enum timeType type)
{
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_month_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned long local_time = (long)big_to_small_endian_32bit(time);
    unsigned int local_year = 1904+local_time/3600/24/365;//此处当做是每年365天，下面再微调

    int leap_years_count;//闰年数量
    //平年，不精确计算
    if(local_year % 4)
    {
        leap_years_count = (local_year - 1904)/4 + 1;
    }
    //闰年
    else
    {
        leap_years_count = (local_year - 1904)/4;
    }
    unsigned int day_count;//由于上面把每年当作365天，此处计算到年初时过去的实际天数
    day_count = leap_years_count*366 + (local_year-1904-leap_years_count)*365;

    int leave_day_count = local_time/3600/24 - day_count;//算出剩下的天数
    int i=0;
    int sum = 31;
    int local_month = 0;
    int local_day = 0;
    /*下面程序算出一年中的哪一个月和哪一天*/
    //平年
    if(local_year % 4)
    {
        while(leave_day_count > sum)
        {
            local_day = leave_day_count - sum + 1;//因为从零算起，所以天数要加1
            sum += month_days[++i];
        }
    }
    //闰年
    else
    {
        while(leave_day_count > sum)
        {
            local_day = leave_day_count - sum + 1;
            sum += leap_month_days[++i];
        }
    }

    local_month = i+1;
    if(local_month == 1)//如果是一月份
    {
        local_day = leave_day_count + 1;
    }
    /*上面程序算出一年中的哪一个月和哪一天*/

    int out_of_day = leave_day_count + day_count;
    int leave_second = local_time - out_of_day * 3600 *24;//计算剩下的秒数
    if(type == CREATE_TIME)
    {
        printf("编码时间：%d-%d-%d %d:%d:%d\n", local_year, local_month, local_day,
                                              leave_second/3600, leave_second%3600/60, leave_second%60);
    }
    else if(type == MODIFY_TIME)
    {
        printf("修订时间：%d-%d-%d %d:%d:%d\n", local_year, local_month, local_day,
                                              leave_second/3600, leave_second%3600/60, leave_second%60);
    }


}

void mainmenu()
{
    printf("------------------------function menu-------------------------\n");
    printf("1.编码时间与修订时间\n");
    printf("2.影片长度\n");
    printf("3.影片声音采样频率、视频帧率、码率（比特率）、分辨率\n");
    printf("4.视频关键帧列表\n");
    printf("q.输入q退出\n");
    printf("------------------------function menu-------------------------\n");
}

char get_user_input()
{
    char select;
/*这里scanf必须有\n或者空格，看下面的解释

scanf("%c",&c) 与 scanf(" %c",&c)，后者只是在%前多了个空格，似乎没有什么区别，
但使用起来区别是很大的。scanf()作单字符输入时规定只接收一个字符，但它却把回车符
也作为字符对待的。这就造成程序中只有一个输入字符的scanf()语句时，问题还不大，
但如果后面还跟着第二个scanf()字符输入语句，这个scanf()就把前面输入的驾车符当作
输入字符了。这就在输入逻辑上造成了混乱，达不到人们预期的愿望。有了这个空格，
因为scanf()是跳过空格读字符的，就回避了这个问题。实践证明，这个空格放在%c后面也不能达到目的。
应当说，这也是比较巧妙的应用！
    */
    scanf(" %c", &select);
    switch(select)
    {
        case '1':
        {
            create_and_modify_time(mp4_info.create_time, CREATE_TIME);
            create_and_modify_time(mp4_info.modification_time, MODIFY_TIME);
        }
        break;

        case '2':
        {

        }
        break;

        case '3':
        {

        }
        break;

        case '4':
        {

        }
        break;

        case '5':
        {

        }
        break;

    }
    return select;
}

Ret_Boxhead_Fileptr moov_box_parse(FILE *p)
{
    BOX_HEAD box_head;
    MOOV_HEADER_BOX mvhd_box;
    char version;
    char *flag = (char *)malloc(3);
    bool stbl_flag = false;

    fread(&box_head, sizeof(BOX_HEAD), 1, p);
    print_box_type(box_head.type, 1);//mvhd box

    fread(&version, sizeof(char), 1, p);
    fread(flag, 3, 1, p);
    fread(&mvhd_box, sizeof(MOOV_HEADER_BOX), 1, p);

    mp4_info.create_time = mvhd_box.create_time;
    mp4_info.modification_time = mvhd_box.modification_time;

    fread(&box_head, sizeof(BOX_HEAD), 1, p);
    while(big_to_small_endian_32bit(box_head.type) != TRAK_BOX)
    {
        print_box_type(box_head.type, 1);
        fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
        fread(&box_head, sizeof(BOX_HEAD), 1, p);
    }

    print_box_type(box_head.type, 1);//trak box
    while(big_to_small_endian_32bit(box_head.type) != MDAT_BOX &&
          big_to_small_endian_32bit(box_head.type) != FREE_BOX)
    {
        if(0 == fread(&box_head, sizeof(BOX_HEAD), 1, p))
        {
            break;
        }

        while(big_to_small_endian_32bit(box_head.type) != TRAK_BOX &&
              big_to_small_endian_32bit(box_head.type) != MDAT_BOX &&
              big_to_small_endian_32bit(box_head.type) != FREE_BOX )
        {
            switch(big_to_small_endian_32bit(box_head.type))
            {
                case TKHD_BOX:
                {
                    print_box_type(box_head.type, 2);//tkhd box
                    char tkhd_version;
                    char *tkhd_flag = (char *)malloc(3);
                    TRACK_HEAD_BOX tkhd_box;

                    fread(&tkhd_version, 1, 1, p);
                    fread(tkhd_flag, 3, 1, p);
                    fread(&tkhd_box, sizeof(TRACK_HEAD_BOX), 1, p);
                    free(tkhd_flag);
                }
                break;

                case MDIA_BOX:
                {
                    char mdhd_version;
                    char *mdhd_flag = (char *)malloc(3);
                    unsigned int minf_head_box_length;
                    unsigned int handler_type;

                    MDHD_HEAD_BOX mdhd_box;

                    print_box_type(box_head.type, 2);//mdia box

                    fread(&box_head, sizeof(BOX_HEAD), 1, p);

                    print_box_type(box_head.type, 3);//mdhd box


                    fread(&mdhd_version, 1, 1, p);
                    fread(mdhd_flag, 3, 1, p);
                    fread(&mdhd_box, sizeof(MDHD_HEAD_BOX), 1, p);

                    fread(&box_head, sizeof(BOX_HEAD), 1, p);
                    print_box_type(box_head.type, 3);//hdlr box

                    fseek(p, 8, SEEK_CUR);
                    fread(&handler_type, 4, 1, p);
                    fseek(p, big_to_small_endian_32bit(box_head.size)-20, SEEK_CUR);

                    fread(&box_head, sizeof(BOX_HEAD), 1, p);
                    print_box_type(box_head.type, 3);//minf box

            /*      fread(&minf_head_box_length, 4, 1, p);//minf head box
                    fseek(p, big_to_small_endian_32bit(minf_head_box_length)-4, SEEK_CUR);
                    fread(&box_head, sizeof(BOX_HEAD), 1, p);
                    while(big_to_small_endian_32bit(box_head.type) != STBL_BOX)
                    {
                        print_box_type(box_head.type, 4);
                        fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
                        fread(&box_head, sizeof(BOX_HEAD), 1, p);
                    }

                    print_box_type(box_head.type, 4);//stbl box*/
                    switch(big_to_small_endian_32bit(handler_type))
                    {
                        case SOUN:
                        case VIDE:
                        case HINT:
                        {
                            unsigned int now_pos = ftell(p);
                            unsigned int now_box_size = big_to_small_endian_32bit(box_head.size);
                            while((ftell(p)-now_pos+8) != now_box_size)
                            {
                                fread(&box_head, sizeof(BOX_HEAD), 1, p);
                                fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
                                switch(big_to_small_endian_32bit(box_head.type))
                                {
                                    case VMHD_BOX:
                                    case DINF_BOX:
                                    case HMHD_BOX:
                                    case SMHD_BOX:
                                    {
                                        print_box_type(box_head.type, 4);
                                    }
                                    break;

                                    case STBL_BOX:
                                    {
                                        print_box_type(box_head.type, 4);
                                        stbl_flag = true;
                                        fseek(p, 8-big_to_small_endian_32bit(box_head.size), SEEK_CUR);


                                        unsigned int stbl_pos = ftell(p);
                                        unsigned int stbl_box_size = big_to_small_endian_32bit(box_head.size);
                                        while((ftell(p)-stbl_pos+8) != stbl_box_size)
                                        {
                                            fread(&box_head, sizeof(BOX_HEAD), 1, p);
                                            fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
                                            switch(big_to_small_endian_32bit(box_head.type))
                                            {
                                                case STSD_BOX:
                                                {
                                                    print_box_type(box_head.type, 5);
                                                }
                                                break;

                                                case STTS_BOX:
                                                {
                                                    print_box_type(box_head.type, 5);
                                                }
                                                break;

                                                case STSC_BOX:
                                                {
                                                    print_box_type(box_head.type, 5);
                                                }
                                                break;

                                                case STSZ_BOX:
                                                {
                                                    print_box_type(box_head.type, 5);
                                                }
                                                break;

                                                case STCO_BOX:
                                                {
                                                    print_box_type(box_head.type, 5);
                                                }
                                                break;

                                                case STSS_BOX:
                                                {
                                                    print_box_type(box_head.type, 5);
                                                }
                                                break;
                                            }
                                        }


                                    }
                                    break;
                                }
                            }
                        }
                        break;

                        default:
                        {
                            fread(&minf_head_box_length, 4, 1, p);//nmhd
                            print_box_type(NMHD_BOX, 4);
                            fseek(p, big_to_small_endian_32bit(minf_head_box_length)-4, SEEK_CUR);
                            fread(&box_head, sizeof(BOX_HEAD), 1, p);
                            while(big_to_small_endian_32bit(box_head.type) != STBL_BOX)
                            {
                                print_box_type(box_head.type, 4);
                                fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
                                fread(&box_head, sizeof(BOX_HEAD), 1, p);
                            }

                            print_box_type(box_head.type, 4);//stbl box
                        }
                        break;
                    }

                    if(stbl_flag == true)
                    {
                        stbl_flag = false;
                        free(mdhd_flag);
                        break;
                    }

                    unsigned int cur_pos = ftell(p);
                    unsigned int cur_box_size = big_to_small_endian_32bit(box_head.size);
                    while((ftell(p)-cur_pos+8) != cur_box_size)
                    {
                        fread(&box_head, sizeof(BOX_HEAD), 1, p);
                        fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
                        switch(big_to_small_endian_32bit(box_head.type))
                        {
                            case STSD_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;

                            case STTS_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;

                            case STSC_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;

                            case STSZ_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;

                            case STCO_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;

                            case STSS_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;

                            case CTTS_BOX:
                            {
                                print_box_type(box_head.type, 5);
                            }
                            break;
                        }
                    }

                    stbl_flag = false;
                    free(mdhd_flag);
                }
                break;

                default:
                    print_box_type(box_head.type, 2);
                    fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
                    break;
            }

            /*读取到文件末尾跳出*/
            if(0 == fread(&box_head, sizeof(BOX_HEAD), 1, p))
            {
                break;
            }
            if(big_to_small_endian_32bit(box_head.type) == TRAK_BOX)
            {
                print_box_type(box_head.type, 1);
            }
        }
    }
    free(flag);
    Ret_Boxhead_Fileptr ret;
    ret.box_head.size = box_head.size;
    ret.box_head.type = box_head.type;
    ret.p = p;
    return ret;
}

FILE* mdat_box_parse(FILE *p, BOX_HEAD box_head)
{
    int64_t box_large_size;
    if(big_to_small_endian_32bit(box_head.size) != 1)
    {
        fseek(p, big_to_small_endian_32bit(box_head.size)-8, SEEK_CUR);
    }
    else
    {
        fread(&box_large_size, sizeof(int64_t), 1, p);
        fseek(p, big_to_small_endian_64bit(box_large_size)-sizeof(int64_t)-8, SEEK_CUR);
    }
    return p;
}

int main( void )
{
    FILE *p;
    FTYP_BOX ftyp_box;
    BOX_HEAD box_head;
    char filename[256];

    printf("please input mp4 filename:");
    scanf("%s", filename);

    if((p = fopen(filename,"r")) == NULL)
    {
        printf("open fail\n");
        return -1;
    }
    printf("----------------------MP4 file structure----------------------\n");
    fread(&ftyp_box, sizeof(FTYP_BOX), 1, p);
    print_box_type(ftyp_box.ftyp_type, 0);//ftyp box

    fseek(p, big_to_small_endian_32bit(ftyp_box.ftyp_size), SEEK_SET);
    fread(&box_head, sizeof(BOX_HEAD), 1, p);
    print_box_type(box_head.type, 0);//moov box OR mdat box
    switch(big_to_small_endian_32bit(box_head.type))
    {
        case MDAT_BOX:
        {
            p = mdat_box_parse(p, box_head);
            fread(&box_head, sizeof(BOX_HEAD), 1, p);
            print_box_type(box_head.type, 0);//moov box
            moov_box_parse(p);
        }
        break;

        case MOOV_BOX:
        {
            Ret_Boxhead_Fileptr ret;
            ret = moov_box_parse(p);
            print_box_type(ret.box_head.type, 0);
            mdat_box_parse(ret.p, ret.box_head);
        }
        break;

        default:
        break;
    }
    fclose(p);
    printf("----------------------MP4 file structure----------------------\n\n\n");

    mainmenu();
    while(get_user_input() != 'q')
    {
        mainmenu();
    }
    return 0;
}
