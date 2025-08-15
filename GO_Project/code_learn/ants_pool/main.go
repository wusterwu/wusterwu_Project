package main

import (
	"fmt"
	"sync"
	"time"

	"github.com/panjf2000/ants/v2"
)

// This is the entry point of the ants_pool application.
func main() {
	// Example usage of the ants package to create a worker pool
	workerPool, err := ants.NewPool(3)
	if err != nil {
		panic(err)
	}
	defer workerPool.Release() // Ensure the pool is released when done

	// Submit tasks to the worker pool
	var wg sync.WaitGroup
	for i := 0; i < 10; i++ {
		wg.Add(1)
		num := i // Capture the current value of i
		// Submit a task to the worker pool
		err = workerPool.Submit(func() {
			// Do some work
			time.Sleep(3 * time.Second) // Simulate work with a sleep
			fmt.Printf("Task %d executed ,current datetime :%v\n", num, time.Now().Format("2006-01-02 15:04:05"))
			defer wg.Done()
		})
		if err != nil {
			wg.Done()
		}
	}
	wg.Wait()
	fmt.Println("All tasks completed!!!")
}
