#include "buffer.h"


Buffer::Buffer()
{
  count = 0;
}

void Buffer::displayBuffer()
{
  cout << "The current content of the buffer is [ ";
  
  if(isEmpty())
  {
    cout << "Buffer is empty!" << endl;
  }

  else
  {
    for(int i = 0; i < count; i++)
    {
      cout << " " << buffer[i];
    }
  }
  cout << " ]" << endl;
}

int Buffer::insert_item(buffer_item item) 
{ 
  /* insert item into buffer
  return 0 if successful, otherwise
  return -1 indicating an error condition */
  
  if(count < BUFFER_SIZE){
    buffer[count] = item;
    count++;
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
  *item = buffer[count];
  buffer[count] = 0;
  count--;

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
