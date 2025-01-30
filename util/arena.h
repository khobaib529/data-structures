#ifndef DS_UTIL_ARENA_H_
#define DS_UTIL_ARENA_H_

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace ds {

class Arena {
 public:
  Arena();

  Arena(const Arena&) = delete;
  Arena& operator=(const Arena&) = delete;

  ~Arena();

  // Return a pointer to a newly allocated memory block of "bytes" bytes.
  char* Allocate(size_t bytes);

  // Allocate memory with the normal alignment guarantees provided by malloc.
  char* AllocateAligned(size_t bytes);

  // Returns an estimate of the total memory usage of data allocated
  // by the arena.
  size_t MemoryUsage() const {
    return memory_usage_;
  }

 private:
  enum { kBlockSize = 4096 };
  char* AllocateFallback(size_t bytes);
  char* AllocateNewBlock(size_t block_bytes);

  // Allocation state
  char* alloc_ptr_;
  size_t alloc_bytes_remaining_;

  // Array of new[] allocated memory blocks
  std::vector<char*> blocks_;

  // Total memory usage of the arena.
  size_t memory_usage_;
};

}  // namespace ds

#endif  // DS_UTIL_ARENA_H_
