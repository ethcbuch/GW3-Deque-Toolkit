class deque {
 public:
  deque();
  ~deque();
  push_front();
  push_back();
  pop_front();
  pop_back();
  front();
  back();
  empty();
  size();
  &int operator[](unsigned int index);

 private:
  int** blockmap;
  int size;
  int mapsize;
  const static int blocksize = 3;
  
};
