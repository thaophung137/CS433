#include "buffer.h"


buffer::buffer()
{
  buffer_item buffer[BUFFER_SIZE]; //the buffer
  int count = 0;
}

int buffer::insert_item(buffer_item item) 
{ 
  /* insert item into buffer
  return 0 if successful, otherwise
  return -1 indicating an error condition */
}

int buffer::remove_item(buffer_item *item) 
{ 
  /* remove an object from buffer
  placing it in item
  return 0 if successful, otherwise
  return -1 indicating an error condition */
}

bool buffer::isEmpty()
{
  if(count == 0)
  {
    return true;
  }
  return false;
}

bool buffer:: isFull()
{
  if(count == BUFFER_SIZE)
  {
    return true;
  }
  return false;
}
