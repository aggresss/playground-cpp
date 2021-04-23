#ifndef LOG_STREAMER_V1_H_
#define LOG_STREAMER_V1_H_

#include <iostream>
#include <string>

#define LOG_V1 \
    v1::LogCall(__FILE__, " LOG_V1 ") & v1::LogStreamer()

namespace v1 {

class LogStreamer {
   public:
    explicit LogStreamer(const char* arg = "")
        : log_(arg) {}

    LogStreamer(const LogStreamer&) = default;
    LogStreamer(LogStreamer&&) = default;
    LogStreamer& operator=(const LogStreamer&) = default;
    LogStreamer& operator=(LogStreamer&&) = default;

    LogStreamer operator<<(const char* arg) {
        this->log_.append(arg);
        return *this;
    }

    template <typename... U>
    void Call(U... args) const {
        (std::cout << ... << args) << this->log_ << std::endl;
    }

   private:
    std::string log_;
};

class LogCall final {
   public:
    LogCall(const char* file, const char* message)
        : file_(file), message_(message) {}

    void operator&(const LogStreamer& streamer) {
        streamer.Call(file_, message_);
    }

   private:
    const char* file_;
    const char* message_;
};

}  // namespace v1

#endif  // LOG_STREAMER_V1_H_
