	
35	
// Locate current thread pool from worker thread
static StaticThreadPool* Current();
private:
class Counter {
  public:
   explicit Counter(uint32_t value);
   ~Counter() = default;
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    void Increment();
    void Decrement();
    void WaitNull();
    void StoreNull();
    void NotifyIfZero();
   twist::stdlike::mutex mutex_;
   private:
     uint32_t counter_ = 0;
     twist::stdlike::condition_variable is_zero_;
};
  void StartWorkerThreads(size_t count);
  void WorkerRoutine();
  void JoinWorkers();
  std::vector<twist::stdlike::thread> workers_;

void StaticThreadPool::Join() {
 pending_tasks_.WaitNull();
  tasks_.Close();
  JoinWorkers();
}
	
void StaticThreadPool::Shutdown() {
  pending_tasks_.StoreNull();
  tasks_.Cancel();
  JoinWorkers();
}

StaticThreadPool* StaticThreadPool::Current() {
 return *pool;
}
void StaticThreadPool::StartWorkerThreads(size_t count) {
void StaticThreadPool::WorkerRoutine() {
  *pool = this;
  while (true) {
  auto task = tasks_.Take();
  if (task == std::nullopt) {
  break;
}
  ExecuteHere((task.value()));
  std::lock_guard lock(pending_tasks_.mutex_);
  pending_tasks_.Decrement();
  pending_tasks_.NotifyIfZero();
