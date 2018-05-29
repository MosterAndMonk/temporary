#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    using namespace boost::interprocess;

    if(argc == 1){
        struct shm_remove{
            shm_remove(){shared_memory_object::remove("MySharedMemory");}
            ~shm_remove(){shared_memory_object::remove("MySharedMemory");}
        }remover;

        shared_memory_object shm(create_only, "MySharedMemory", read_write);

        shm.truncate(1000);

        mapped
    }else{
    }
    shared_memory_object shm_obj(create_only, "shared_memory", read_write);

    shm_obj.truncate(10000);

    shared_memory_object::remove("shared_memory");

    size_t ShmSize = 10;

    mapped_region region
        ( shm_obj
         ,read_write
         ,ShmSize/2
         ,ShmSize-ShmSize/2
         );
    region.get_address();

    region.get_size();

    return 0;
}
