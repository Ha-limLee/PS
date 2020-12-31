import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Point{
	private int x;
	private int y;

	public static final int LESS = -1;
	public static final int SAME = 0;
	public static final int GREATER = 1;

	public Point(int x, int y){
		this.x = x;
		this.y = y;
	}
	public int getX(){return x;}
	public int getY(){return y;}
	public int compare(Point p){
		if (this.getX() > p.getX())
			return GREATER;
		else if (this.getX() < p.getX())
			return LESS;
		else{
			if (this.getY() > p.getY())
				return GREATER;
			else if (this.getY() < p.getY())
				return LESS;
			else
				return SAME;
		}
	}
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

	public BinarySearchTree(){}
	public void insert(Node node){
		if (head == null){
			head = node;
			return;
		}

		Node current = head;
		Node parent = null;
		while(true){
			parent = current;
			if (node.data.compare(current.data) == Point.GREATER){
				if (current.hasThread){
					Node temp = current.right;
					current.right = node;
					current.hasThread = false;
					node.right = temp;
					node.hasThread = true;
					return;
				}
				else{
					current = current.right;
					if (current == null){
						parent.right = node;
						return;
					}
				}
			}
			else if (node.data.compare(current.data) == Point.LESS){
				current = current.left;
				if (current == null){
					parent.left = node;
					node.right = parent;
					node.hasThread = true;
					return;
				}
			}
		}
	}

	public Node leftMost(Node current){
		if (current == null)
			return null;
		
		while(current.left != null){
			current = current.left;
		}
		return current;
	}

	public void inorderTraverse(){
		Node current = leftMost(head);
		while(current != null){
			System.out.println(current.data.getX() + " " + current.data.getY());
			if (current.hasThread)
				current = current.right;
			else
				current = leftMost(current.right);
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