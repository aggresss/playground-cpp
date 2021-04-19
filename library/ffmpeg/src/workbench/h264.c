int GetH264Stream()
{
    int ret;
    AVFormatContext *ic=NULL;
    AVFormatContext *oc=NULL;

    uint8_t sps[100];
    uint8_t pps[100];
    int spsLength=0;
    int ppsLength=0;
    uint8_t startcode[4]={00,00,00,01};
    FILE *fp;

    fp=fopen("123.h264","wb+");

    char *InputFileName="11111.mp4";

    if ((ret = avformat_open_input(&ic, InputFileName, NULL, NULL)) < 0)
    {
        return ret;
    }

    if ((ret = avformat_find_stream_info(ic, NULL)) < 0)
    {
        avformat_close_input(&ic);
        return ret;
    }

    spsLength=ic->streams[0]->codec->extradata[6]*0xFF+ic->streams[0]->codec->extradata[7];

    ppsLength=ic->streams[0]->codec->extradata[8+spsLength+1]*0xFF+ic->streams[0]->codec->extradata[8+spsLength+2];

    for (int i=0;i<spsLength;i++)
    {
        sps[i]=ic->streams[0]->codec->extradata[i+8];
    }

    for (int i=0;i<ppsLength;i++)
    {
        pps[i]=ic->streams[0]->codec->extradata[i+8+2+1+spsLength];
    }


    for(int i=0;i<ic->nb_streams;i++)
    {
        if(ic->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoindex=i;
        }
        else if(ic->streams[i]->codec->codec_type==AVMEDIA_TYPE_AUDIO)
        {
            audioindex=i;
        }
    }

    AVOutputFormat *ofmt = NULL;
    AVPacket pkt;

    avformat_alloc_output_context2(&oc, NULL, NULL, OutPutPath);

    if (!oc)
    {
        printf( "Could not create output context\n");
        ret = AVERROR_UNKNOWN;
    }
    ofmt = oc->oformat;
    int i;

    for (i = 0; i < ic->nb_streams; i++)
    {
        AVStream *in_stream = ic->streams[i];
        AVStream *out_stream = avformat_new_stream(oc, in_stream->codec->codec);

        if (!out_stream)
        {
            printf( "Failed allocating output stream\n");
            ret = AVERROR_UNKNOWN;
        }
        ret = avcodec_copy_context(out_stream->codec, in_stream->codec);
        if (ret < 0)
        {
            printf( "Failed to copy context from input to output stream codec context\n");
        }
        out_stream->codec->codec_tag = 0;
        if (oc->oformat->flags & AVFMT_GLOBALHEADER)
            out_stream->codec->flags |= CODEC_FLAG_GLOBAL_HEADER;
    }

    if (!(ofmt->flags & AVFMT_NOFILE))
    {
        ret = avio_open(&oc->pb, OutPutPath, AVIO_FLAG_WRITE);
        if (ret < 0)
        {
            printf( "Could not open output file '%s'", OutPutPath);

        }
    }
    ret = avformat_write_header(oc, NULL);

    int frame_index=0;
    int flag=1;

    av_init_packet(&pkt);
    pkt.data = NULL;
    pkt.size = 0;

    while (1)
    {
        AVStream *in_stream, *out_stream;

        ret = av_read_frame(ic, &pkt);

        if (ret < 0)
            break;
        in_stream  = ic->streams[pkt.stream_index];
        out_stream = oc->streams[pkt.stream_index];

        AVPacket tmppkt;
        if (in_stream->codec->codec_type==AVMEDIA_TYPE_VIDEO )
        {

            if (flag)
            {
                fwrite(startcode,4,1,fp);
                fwrite(sps,spsLength,1,fp);
                fwrite(startcode,4,1,fp);
                fwrite(pps,ppsLength,1,fp);

                pkt.data[0]=0x00;
                pkt.data[1]=0x00;
                pkt.data[2]=0x00;
                pkt.data[3]=0x01;
                fwrite(pkt.data,pkt.size,1,fp);

                flag=0;
            }
            else
            {
                pkt.data[0]=0x00;
                pkt.data[1]=0x00;
                pkt.data[2]=0x00;
                pkt.data[3]=0x01;
                fwrite(pkt.data,pkt.size,1,fp);
            }

            pkt.pts = av_rescale_q_rnd(pkt.pts, in_stream->time_base, out_stream->time_base, (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
            pkt.dts = av_rescale_q_rnd(pkt.dts, in_stream->time_base, out_stream->time_base, (AVRounding)(AV_ROUND_NEAR_INF|AV_ROUND_PASS_MINMAX));
            pkt.duration = av_rescale_q(pkt.duration, in_stream->time_base, out_stream->time_base);
            pkt.pos = -1;

            pkt.stream_index=0;
            ret = av_interleaved_write_frame(oc, &pkt);
        }

        av_free_packet(&pkt);
    }

    fclose(fp);
    fp=NULL;

    av_write_trailer(oc);
    return 0;
}
