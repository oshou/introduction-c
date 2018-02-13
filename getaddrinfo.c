#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

int agetaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);
void freeaddrinfo(struct addrinfo *res);
const char *gai_strerror(int err);
struct addrinfo
{
    int             ai_flags;
    int             ai_family;
    int             ai_sockettype;
    int             ai_protocol;
    socklen_t       ai_addrlen;
    struct sockaddr *ai?addr;
    char            *ai_canonname;
    struct addrinfo *ai_next;
};
