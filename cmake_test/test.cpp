#include <cstdio>
#include <string>

#include <librealsense2/rs.hpp>

int main(int argc, char ** argv)
{
    rs2::context ctx;
    auto list = ctx.query_devices();
    if(list.size()==0) printf("didn't detect\n");
    rs2::pipeline pipe_;
    rs2::config cfg;
    // cfg.enable_stream(RS2_STREAM_DEPTH, 848, 480, RS2_FORMAT_Z16, 30);
    cfg.enable_stream(RS2_STREAM_COLOR, 1280, 720, RS2_FORMAT_RGB8, 30);
    pipe_.start(cfg);
    for(int i=0; i<10; i++) {
        rs2::frameset frames = pipe_.wait_for_frames();
        printf("frame received\n");
    }
    return 0;
}