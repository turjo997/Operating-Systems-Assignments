/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer_assignment;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author User
 */
public class ProducerConsumer_Assignment {

    /**
     * @param args the command line arguments
     */
        int bufferSize = 10;
    //buffer to store produced item
    private final Queue<Integer> buffer = new LinkedList<>();
    
    //binary semaphore to lock/unlock critical section
    Semaphore mutex = new Semaphore(1);
    
    //counting semaphore to coordinate access to resources
    Semaphore full = new Semaphore(0);
    Semaphore empty = new Semaphore(bufferSize);
    
    //random object to generate random number to store in buffer
    Random rand = new Random();
    
   
    Scanner sc = new Scanner(System.in);
    
    //inner Producer Class implements interface Runnable
    class Producer implements Runnable {

        @Override
        public void run() {
            //calling Producer Process Method
          //  ProduceProcess();
           while (true) {
            try {
                //generating random number within 0 to 999
                
                int produced_item = rand.nextInt(1000);
                
                //decrement empty semaphore count by 1
                empty.acquire();
                
                //locking critical section
                mutex.acquire();
                
                //adding produced item to buffer
                buffer.add(produced_item);
                
                //output
                System.out.println(Thread.currentThread().getName() + " : Data " + produced_item + " is inserted in the buffer");
                System.out.println("Empty Space : "+ (bufferSize - buffer.size()));
                System.out.println("Full Space : " + buffer.size());
                
                //unlocking critical section
                mutex.release();
                
                //increment full semaphore count by 1
                full.release(1);
                
                //send thread to sleep for 1 second
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducerConsumer_Assignment.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
        }
    }

    //inner Consumer Class implements interface Runnable
    class Consumer implements Runnable {

        @Override
        public void run() {
            //calling Consumer Process Method
           // ConsumeProcess();
           
           while (true) {
            try {
                //decrement full semaphore count by 1
                full.acquire();
                
                //locking critical section
                mutex.acquire();
                
                //consuming data from buffer
                int consumed_item = buffer.remove();
                
                //output
                System.out.println(Thread.currentThread().getName() + " : Consumed Data " + consumed_item + " from the buffer");
                System.out.println("Full Space : " + buffer.size());
                
                //unlocking critical section
                mutex.release();
                //increment empty semaphore by 1 - releasing resource
                empty.release();
                Thread.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(ProducerConsumer_Assignment.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
            
            
        }
    }

    public static void main(String[] args) {
        // TODO code application logic here
        
         ProducerConsumer_Assignment pc = new ProducerConsumer_Assignment();

        //creating 3 producer object
        Producer p1 = pc.new Producer();
        Producer p2 = pc.new Producer();
        Producer p3 = pc.new Producer();

        //creating 2 consumer object
        Consumer c1 = pc.new Consumer();
        Consumer c2 = pc.new Consumer();

        
        //Creating 3 Produced thread
        Thread t1 = new Thread(p1);
        t1.setName("Producer 1");
        Thread t2 = new Thread(p2);
        t2.setName("Producer 2");
        Thread t5 = new Thread(p3);
        t5.setName("Producer 3");
        
        //creating 2 Consumer thread
        Thread t3 = new Thread(c1);
        t3.setName("Consumer 1");
        Thread t4 = new Thread(c2);
        t4.setName("Consumer 2");

        
        //starting the producer and consumer threads
        t1.start();
        t2.start();
        t5.start();
        
        t3.start();
        t4.start();
    }
    
}
