import java.util.*;

public class Exercise {
	public ApparatusType at;
	public Map<WeightPlateSize, Integer> weight;
	public int duration;
	
	public Exercise(ApparatusType at, Map<WeightPlateSize, Integer> weight, int duration){
		this.at = at;
		this.weight = weight;
		this.duration = duration;
	}
	
	public static Exercise generateRandom(Map<WeightPlateSize, Integer> map){
		return new Exercise(ApparatusType.getRandom(), map, (int) (Math.random()*10));
	}
}
