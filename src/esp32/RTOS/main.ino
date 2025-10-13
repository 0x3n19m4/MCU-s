#define MAX_TASKS 8
#define STACK_SIZE 1024

typedef struct {
  bool TASK_READY;
  bool TASK_RUNNING;
  bool TASK_WAITING;
  bool TASK_DEAD;
} task_state_t;

typedef struct {
  void (*fn)(void*);
  void *arg;
  task_state_t state;
  uint8_t *stack;
  int id;  
} tcb_t;

static tcb_t task[MAX_TASKS];
static int task_count = 0;
static int current = -1;

int task_create(void (*fn)(void), void *arg)
{
  if (task_count >= MAX_TASKS)
  {
    return -1;  
  }
  
}

void task_sheduler()
{
  
}

void task_yeild()
{
  
}

void setup()
{
  
}

void loop()
{
  
}
