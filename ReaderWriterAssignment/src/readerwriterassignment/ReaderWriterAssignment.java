/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package readerwriterassignment;

/**
 *
 * @author User
 */

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ReaderWriterAssignment{
    
    int bufferSize = 10;
    //buffer to store produced item
    private final Queue<Integer> buffer = new LinkedList<>();

    
    
    static Semaphore readLock = new Semaphore(1);
    static Semaphore writeLock = new Semaphore(1);
    static int readCount = 0;

    Random rand = new Random();
  
    Scanner sc = new Scanner(System.in);
    
     class Read implements Runnable {
        @Override
        public void run() {
            try { 
                int reading_item = rand.nextInt(1000);
               
                //adding produced item to buffer
                buffer.add(reading_item);
                
                //Acquire Section
               
                readLock.acquire();
                readCount++;
                if (readCount == 1) {
                    writeLock.acquire();
                }
                readLock.release();

                //Reading section
                System.out.println("Thread "+Thread.currentThread().getName() + " : Data " + reading_item + " is READING");
                Thread.sleep(1500);
                System.out.println("Thread "+Thread.currentThread().getName() + " has FINISHED READING");

                //Releasing section
                readLock.acquire();
                readCount--;
                if(readCount == 0) {
                    writeLock.release();
                }
                readLock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

     class Write implements Runnable {
        @Override
        public void run() {
            try {
                writeLock.acquire();
                
                int writing_item = buffer.remove();
                 
                 
                System.out.println("Thread "+Thread.currentThread().getName() + " : Data " + writing_item + " is WRITING");
                Thread.sleep(2500);
                System.out.println("Thread "+Thread.currentThread().getName() + " has finished WRITING");
                writeLock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public static void main(String[] args) throws Exception {
        
        
       ReaderWriterAssignment pc = new ReaderWriterAssignment();

        //creating 3 reder writer object
        Read read = pc.new Read();
        Write write = pc.new Write();
    
       
        Thread t1 = new Thread(read);
        t1.setName("thread1");
        Thread t2 = new Thread(read);
        t2.setName("thread2");
        Thread t3 = new Thread(write);
        t3.setName("thread3");
        Thread t4 = new Thread(read);
        t4.setName("thread4");
        t1.start();
        t3.start();
        t2.start();
        t4.start();
    }
}