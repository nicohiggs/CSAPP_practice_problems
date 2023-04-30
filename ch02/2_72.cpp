// the probelm is size_t is unsigned which leads to an implicit casting
// which leads to maxbytes-sizeof(val) being unsigned and thus always >= 0
// we use casting to overcome this

void copy_int(int val, void *buf,int maxbytes) {
  if (maxbytes >= (int) sizeof(val)) {
    memcpy(buf, (void *) &val, sizeof(val));
  }
}
