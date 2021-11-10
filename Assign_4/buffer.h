#pragma once

typedef int buffer_item;
#define BUFFER_SIZE 5

using namespace std;

class buffer
{
  public:
    buffer();
    int insert_item(buffer_item item);
    int remove_item(*buffer_item item);
    bool isFull();
    bool isEmpty();
  private:
    int count;
};
