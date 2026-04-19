import threading
import time
from threading import Semaphore, Lock

total_people = 5
EAT_COUNT = 1

fork = [Semaphore(1) for _ in range(total_people)]
print_lock = Lock()   # to avoid mixed output

def dine(person_id):
    with print_lock:
        print(f'P{person_id} thinking') 

    time.sleep(1)

    fork[person_id].acquire()
    fork[(person_id + 1) % total_people].acquire()
    with print_lock:
        print(f'P{person_id} eating')

    time.sleep(1)

    fork[person_id].release()
    fork[(person_id + 1) % total_people].release()

    with print_lock:
        print(f'P{person_id} done')

workers = []

for i in range(total_people):
    t = threading.Thread(target=dine, args=(i,))
    workers.append(t)
    t.start()

for t in workers:
    t.join()

print("Finished execution")