import java.util.HashMap;
import java.util.Map;

public enum WeightPlateSize {
	SMALL_3KG,
	MEDIUM_5KG,
	LARGE_10KG;
	
	public static Map<WeightPlateSize, Integer> getRandom() {
		//gives a map of all plate sizes with a random number of those plates; there must be at least 1, a max of 30
		int rand = (int) (Math.random() * 10);
		int randd = (int) (Math.random() * 10);
		int randdd = (int) (Math.random() * 10);
		Map<WeightPlateSize, Integer> map = new HashMap<WeightPlateSize, Integer>();
		while( (rand+randd+randdd) < 1)
			randd = (int) (Math.random() * 10);
		map.put(SMALL_3KG, rand);
		map.put(MEDIUM_5KG, randd);
		map.put(LARGE_10KG, randdd);	
		return map;
	}
	
	public static Map<WeightPlateSize, Integer> intial(){
		//returns the map of the plates in the gym; 20, 30 ,40; large, medium, small
		Map<WeightPlateSize, Integer> map = new HashMap<WeightPlateSize, Integer>();
		map.put(SMALL_3KG, 40);
		map.put(MEDIUM_5KG, 30);
		map.put(LARGE_10KG, 20);
		return map;
	}
}
