#pragma once

typedef int buffer_item;
#define BUFFER_SIZE 5

using namespace std;

class Buffer
{
  public:
    Buffer();
    int insert_item(buffer_item item);
    int remove_item(buffer_item *item);
    bool isFull();
    bool isEmpty();
  private:
    int count;
    buffer_item buffer[BUFFER_SIZE];
};
