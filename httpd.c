/*
 * httpd.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <ctype.h>
#include <signal.h>

/*************** constants ******************************************/
#define SERVER_NAME "LittileHTTP"
#define SERVER_VERSION "1.0"
#define HTTP_MINOR_VERSION 0
#define BLOCK_BUF_SIZE 1024
#define LINE_BUF_SIZE 4096
#define MAX_REQUEST_BODY_LENGTH (1024 * 1024)


/*************** data type definition *******************************/

// Link-list
struct HTTPHeaderField{
    char *name;
    char *value;
    struct HTTPHeaderField *next;
}

struct HTTPRequest{
    // HTTP Version
    int protocol_minor_version;
    // HTTP Request Method (GET, HEAD, POST...etc)
    char *method;
    // HTTP Request Path (/ja/linuxprog/index.html...etc)
    char *path;
    // HTTP Header
    struct HTTPHeaderField *header;
    // HTTP Body
    char *body;
    // HTTP Body Size
    long length;
};

struct FileInfo{
    char *path;
    long size;
    int ok;
}

/*************** function prototypes ********************************/
//typedef void (*sighandler_t)(int);
static void install_signal_handlers(void);
static void trap_signal(int sig, sighandler_t handler);
//static void signal_exit(int sig);
static void service(FILE *in, FILE *out, char *docroot);
static void free_request(struct HTTPRequest *req);
static void log_exit(char *fmt, ...);
static void* xmalloc(size_t sz);


/*************** functions ******************************************/
int main(int argc, char *argv[])
{
    if (argc != 2){
        fprintf(stderr, "Usage: %s <docroot>\n", argv[0]);
        exit(1);
    }
    install_signal_handlers();
    service(stdin, stdout, argv[1]);
    exit(0);
}


static void install_signal_handlers(void)
{
    trap_signal(SIGPIPE, signal_exit);
}

static void trap_signal(int sig, sighandler_t handler)
{
    struct sigaction act;

    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    if (sigaction(sig, &act, NULL) < 0)
        log_exit("sigction() failed: %s",strerror(errono));
}

static void service(FILE *in, FILE *out, char *docroot)
{
    struct HTTPRequest *req;

    req = read_request(in);
    respond_to(req, out, docroot);
    // purge request
    free_request(req);
}


static void free_request(struct HTTPRequest *req)
{
    struct HTTPHeaderField *h, *head;

    head = req->header;
    while (head){
        h = head;
        head = head->next;
        free(h->name);
        free(h->value);
        free(h);
    }
    free(req->method);
    free(req->path);
    free(req->body);
    free(req);
}


static void* xmalloc(size_t sz)
{
    void *p;
    p = malloc(sz);
    if (!p) log_exit("failed to allocate memory");
    return p;
}

static void log_exit(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(1);
}
