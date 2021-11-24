#include "buffer.h"

//PURPOSE: default constructor for Buffer
Buffer::Buffer()
{
  count = 0;
}

//PURPOSE: display the buffer
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

//PURPOSE: insert item to the buffer
int Buffer::insert_item(buffer_item item) 
{ 
  /* insert item into buffer
  return 0 if successful, otherwise
  return -1 indicating an error condition */
  
  if(!isFull()){
    buffer[count] = item;
    count++;

    return 0;
  }
    return -1;
  
}

//PURPOSE: remove item from the buffer
int Buffer::remove_item(buffer_item *item) 
{ 
  /* remove an object from buffer
  placing it in item
  return 0 if successful, otherwise
  return -1 indicating an error condition */

  if(!isEmpty())
  {
    *item = buffer[count-1];
    count--;

    return 0;
  }

  return -1;

}

//PURPOSE: check if buffer is empty
bool Buffer::isEmpty()
{
  if(count == 0)
  {
    return true;
  }
  return false;
}

//PURPOSE: check if buffer is full
bool Buffer::isFull()
{
  if(count == BUFFER_SIZE)
  {
    return true;
  }
  return false;
}
