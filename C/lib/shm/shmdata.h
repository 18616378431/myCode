#ifndef SHMDATA_H_
#define SHMDATA_H_

#define TEXT_SIZE 2048

struct share_used_st
{
    int written;
    char text[TEXT_SIZE];
};

#endif
