#pragma once

#define QEUUE_NO_MSG                    (-1)
#define QUEUE_ERROR                     (-2)
#define QUEUE_END                       (-3)


#define QUEUE_NODE_DEFAULT_SIZE         (1024*64)


void*
queue_create(   const unsigned int  per_node_size,
                unsigned char       *return_err_buf);

// writer thread function ======================================================
int
queue_write_message(const void          *queue,
                    const unsigned char *msg,
                    const unsigned int  msg_len,
                    unsigned char       *return_err_buf);

int
queue_write_end(const void *queue);

// reader thread function ======================================================
int
queue_read_message( void            *queue,
                    unsigned char   **ret_msg_ptr,
                    unsigned int    *msg_len,
                    unsigned char   *errret_buf);

unsigned char
queue_test_end(void *queue);

void*
queue_destory(void *queue);