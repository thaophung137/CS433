#include "buffer.h"


Buffer::Buffer()
{
  count = 0;
  bufferIndex = 0;
}

int Buffer::insert_item(buffer_item item) 
{ 
  /* insert item into buffer
  return 0 if successful, otherwise
  return -1 indicating an error condition */
  
  if(bufferIndex < BUFFER_SIZE){
    buffer[bufferIndex] = item;
    bufferIndex++;
    return 0;
  }
  else{
    return -1;
  }
}

int Buffer::remove_item(buffer_item *item) 
{ 
  /* remove an object from buffer
  placing it in item
  return 0 if successful, otherwise
  return -1 indicating an error condition */
  *item = buffer[bufferIndex];
  buffer[bufferIndex] = 0;
  bufferIndex--;

  return 0;

}

bool Buffer::isEmpty()
{
  if(count == 0)
  {
    return true;
  }
  return false;
}

bool Buffer:: isFull()
{
  if(count == BUFFER_SIZE)
  {
    return true;
  }
  return false;
}
