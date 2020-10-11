package main

import (
	"io"
	"log"
	"os"
	"os/exec"
)

type writer struct {
	in io.WriteCloser
	cmd *exec.Cmd
}

func NewWriter(w io.Writer) io.WriteCloser {
	cmd := exec.Command("bzip2")

	//把原本发送到stdout的发送到w
	cmd.Stdout = w

	//向stdin写入
	in, err := cmd.StdinPipe()
	if err != nil {
		panic(err)
	}

	//开始
	if err := cmd.Start(); err != nil {
		panic(err)
	}
	wc := &writer{in, cmd}
	return wc
}

func (w *writer) Write(data []byte) (int, error) {
	return w.in.Write(data)
}

func (w *writer) Close() error {
	err := w.in.Close()
	cmdErr := w.cmd.Wait()
	if err != nil {
		return err
	}
	if cmdErr != nil {
		return cmdErr
	}
	return nil
}

func main() {
	w := NewWriter(os.Stdout)
	if _, err := io.Copy(w, os.Stdin); err != nil {
		log.Fatalf("bzipper : %v\n", err)
	}
	if err := w.Close(); err != nil {
		log.Fatalf("bzipper : close : %v\n", err)
	}
}