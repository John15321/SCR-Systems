import multiprocessing 


f = open('text_file.txt', 'r') 
Lines = f.readlines()

def send_msgs(conn):
    for line in Lines:
        conn.send(line.strip())
    conn.close()

def recv_msgs(conn):
    while True:
        msg = conn.recv()
        print("#"+msg+"#")

parent_conn, child_conn = multiprocessing.Pipe()

p1 = multiprocessing.Process(target=send_msgs, args=(parent_conn, ))
p2 = multiprocessing.Process(target=recv_msgs, args=(child_conn, ))


p1.start()
p2.start()

p1.join()
p2.join()

f.close()