class deque {
 public:
  /*deque();
  ~deque();
  push_front();
  push_back();
  pop_front();
  pop_back();
  front();
  back();
  empty();
  size();
  */
  void print();
  void Allociation(std::string fileName);
  &int operator[](unsigned int index);

 private:
  int **blockmap;
  int size;
  int mapsize;
  const static int bsize = 3;
  
};
