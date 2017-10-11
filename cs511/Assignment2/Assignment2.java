
class Assignment2 {

	public static void main(String[] args) {
		System.out.println("Inside the main function.");
		Thread thread = new Thread(new Gym());
		System.out.println("Made the Gym");
			thread.start();
			try{
				thread.join();
				System.out.println("Joined the threads");
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
	}
}
