#include <poll.h>
#include "EventLoop.h"
#include "Thread.h"
#include "ThorAssert.h"
using namespace thor;
__thread EventLoop *t_loopInThread = nullptr;

EventLoop::EventLoop() :
    threadId_(getThreadId()), looping_(false) {
  THOR_ASSERT(t_loopInThread == nullptr);
  t_loopInThread = this;
}

void EventLoop::assertInLoopThread() {
  THOR_ASSERT(isInLoopThread() == true);
}

EventLoop::~EventLoop() {
  THOR_ASSERT(looping_ == false);
  t_loopInThread = nullptr;
}

void EventLoop::loop() {
  THOR_ASSERT(!looping_);
  assertInLoopThread();
  looping_ = true;

  poll(nullptr, 0, 5*1000);

  looping_ = false;
}
