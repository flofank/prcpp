
public class Test {

	static {
		System.loadLibrary("JNITut");
	}

	public static native void display();
	
	public static native int increment(int value);
	
	public static void main(String[] args) {
		System.out.println(increment(5));
		display();
	}
	
}
