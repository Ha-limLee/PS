import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Node{
	public int data;
	public Node next = null;
	public Node prev = null;
	public Node(int data){this.data = data;}
}

class Deque{
	private Node front = null;
	private Node back = null;
	private int size = 0;

	public Deque(){}
	public int is_empty(){
		if (size == 0)
			return 1;
		return 0;
	}

	public void push_front(int x){
		Node temp = new Node(x);
		if (is_empty() == 1){
			front = temp;
			back = temp;
		}
		else{
			temp.next = front;
			front.prev = temp;
			front = temp;
		}
		++size;
	}
	public void push_back(int x){
		Node temp = new Node(x);
		if (is_empty() == 1){
			front = temp;
			back = temp;
		}
		else{
			back.next = temp;
			temp.prev = back;
			back = temp;
		}
		++size;
	}
	public int pop_front(){
		if (is_empty() == 1)
			return -1;
		int temp = front.data;
		front = front.next;
		--size;
		return temp;
	}
	public int pop_back(){
		if (is_empty() == 1)
			return -1;
		int temp = back.data;
		back = back.prev;
		--size;
		return temp;
	}
	public int get_size(){
		return size;
	}
	public int get_front(){
		if (is_empty() == 1)
			return -1;
		return front.data;
	}
	public int get_back(){
		if (is_empty() == 1)
			return -1;
		return back.data;
	}
}

public class Main{
	public static void main(String args[]){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String cmd = "";
		String temp = "";
		StringTokenizer st;
		int N, param;

		Deque deque = new Deque();
		try{
			cmd = br.readLine();
			st = new StringTokenizer(cmd);
			N = Integer.parseInt(cmd);
			for (int i = 0; i < N; ++i){
				cmd = br.readLine();
				st = new StringTokenizer(cmd);
				temp = st.nextToken();
				if (temp.equals("push_front")){
					param = Integer.parseInt(st.nextToken());
					deque.push_front(param);
				}
				else if (temp.equals("push_back")){
					param = Integer.parseInt(st.nextToken());
					deque.push_back(param);
				}
				else if (temp.equals("pop_front"))
					System.out.println(deque.pop_front());
				else if (temp.equals("pop_back"))
					System.out.println(deque.pop_back());
				else if (temp.equals("size"))
					System.out.println(deque.get_size());
				else if (temp.equals("empty"))
					System.out.println(deque.is_empty());
				else if (temp.equals("front"))
					System.out.println(deque.get_front());
				else if (temp.equals("back"))
					System.out.println(deque.get_back());
			}
			br.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
//결과 : 런타임 오류.
//반례
//1
//front