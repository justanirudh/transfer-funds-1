#include<pthread.h>
struct account{
  char* name;
  int balance;
};

typedef struct account* Account;

struct transfer {
	char* out;
	char* in;
	int amount;
};

typedef struct transfer* Transfer;

struct account_access{
	char* name;
	int access; //0 means available, 1 means not available
};

typedef struct account_access* Account_Access;

struct state {
	int start_index;
	int num_threads;
	int transfers_size;
	int accounts_size;
	Account accounts;
	Transfer transfers;
	pthread_mutex_t* lock_ptr; 
	pthread_cond_t* cond_ptr;
	Account_Access accesses;
};

typedef struct state* State;

char** str_split(char*, const char);
void* transfer_amount(void*);
Account find_account(Account, int, char*);
Account_Access find_account_access(Account_Access, int, char*);
void access_account(Account_Access, int, char*, char*,  pthread_mutex_t*, pthread_cond_t*);
void release_account(Account_Access, int, char*, char*,  pthread_mutex_t*, pthread_cond_t*);
