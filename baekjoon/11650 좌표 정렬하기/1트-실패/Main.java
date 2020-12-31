import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Point{
	private int x;
	private int y;

	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	public int getX(){return x;}
	public int getY(){return y;}
}

class Node{		//right threaded
	public Point data = null;
	public Node left = null;
	public Node right = null;
	public boolean hasThread = false;

	public Node(Point data){this.data = data;}
}

class BinarySearchTree{
	private Node head = null;
	private int size = 0;

	public BinarySearchTree(){}
	public void insert(Node node){
		if (head == null){
			node.right = node;
			node.hasThread = true;
			head = node;

			++size;
			return;
		}

		Node parent = head;
		while(true){
			if (parent.data.getX() < node.data.getX()){
				if (parent.hasThread == true)
					break;
				parent = parent.right;
			}
			else if (parent.data.getX() > node.data.getX()){
				if (parent.left == null)
					break;
				parent = parent.left;
			}
			else{
				if (parent.data.getY() < node.data.getY()){
					if (parent.hasThread == true)
						break;
					parent = parent.right;
				}
				else{
					if (parent.left == null)
						break;
					parent = parent.left;
				}
			}
		}

		if (parent.data.getX() < node.data.getX()){
			node.right = parent.right;
			node.hasThread = true;

			parent.right = node;
			parent.hasThread = false;
		}
		else if (parent.data.getX() > node.data.getX()){
			node.right = parent;
			node.hasThread = true;

			parent.left = node;
		}
		else{
			if (parent.data.getY() < node.data.getY()){
				if (parent != head){
					node.right = parent.right;
					node.hasThread = true;
				}

				parent.right = node;
				parent.hasThread = false;
			}
			else{
				node.right = parent;
				node.hasThread = true;

				parent.left = node;
			}
		}
		++size;
	}

	public void inorderTraverse(){
		if (head == null) return;

		Node temp = head;

		for (int i = 0; i < this.size; ++i){	
			while(temp.left != null && temp.hasThread == false){
				temp = temp.left;
			}
			System.out.println(temp.data.getX() + " " + temp.data.getY());
			temp = temp.right;
		}
	}
}

public class Main{
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N, x, y;
		String temp;
		StringTokenizer st;

		BinarySearchTree bst = new BinarySearchTree();
		try{
			temp = br.readLine();
			N = Integer.parseInt(temp);
			for (int i = 0; i < N; ++i){
				temp = br.readLine();
				st = new StringTokenizer(temp);
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				bst.insert(new Node(new Point(x, y)));
			}

			bst.inorderTraverse();
			
			br.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
//결과 : 실패.
//반례
//5
//1 1
//1 5
//1 3
//1 2
//1 4