#ifndef THOR_EVENTLOOP_H
#define THOR_EVENTLOOP_H
#include <unistd.h>
#include "NonCopyable.h"
#include "Thread.h"
namespace thor {
class EventLoop : public NonCopyable {
 public:
  EventLoop();
  ~EventLoop();
  bool isInLoopThread() const { return threadId_ == thor::getThreadId(); }
  void assertInLoopThread();
  void loop();
 private:
  const pid_t threadId_;
  bool looping_;
};
};
#endif