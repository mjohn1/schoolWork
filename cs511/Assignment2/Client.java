import java.util.*;

public class Client {
	private int id;
	private ArrayList<Exercise> routine = new ArrayList<Exercise>();
	
	public Client(int id){
		this.setId(id);
		Map<WeightPlateSize, Integer> weights;
		int max = (int) Math.round((Math.random()*(20-15)) + 15);
		
		for(int i = 0; i < max; i++){
			weights = WeightPlateSize.getRandom();
			this.addExercise(Exercise.generateRandom(weights));
		}
	}
	
	public void setId(int id){
		this.id = id;
	}
	
	public int getId(){
		return id;
	}
	
	public void addExercise(Exercise e){
		routine.add(e);
	}
	
	public static Client generateRandom(int id){
		return new Client(id);
	}
	
	public ArrayList<Exercise> getRoutine(){
		return routine;
	}
	
	public void removeFirstExercise(){
		
	}
}
