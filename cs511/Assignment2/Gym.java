import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;

public class Gym implements Runnable {
	private static final int GYM_SIZE = 30;
	private static final int GYM_REGISTERED_CLIENTS = 100;
	private static int count = 0;
	
	private Map<WeightPlateSize, Integer> noOfWeightPlates;
	private Set<Integer> clients;
	private ExecutorService executor;
	
	public Map<ApparatusType, Semaphore> semaAT = new HashMap<ApparatusType, Semaphore>();
	Semaphore checkWeights = new Semaphore(1);
	Semaphore putTakeWeights = new Semaphore(1);
	Semaphore genClient = new Semaphore(1);
	
	public Gym(){
		noOfWeightPlates = WeightPlateSize.intial();
		clients = new HashSet<Integer>();
		/*for(int i = 0; i < GYM_REGISTERED_CLIENTS; i++){
			int x = (int)(Math.random()*10000);
			while(clients.contains(x))
				x = (int)Math.random();
			clients.add(x);
			*/
		}
	
	public void run() {
		executor = Executors.newFixedThreadPool(GYM_SIZE);
		
		for(ApparatusType at : ApparatusType.values()){
			semaAT.put(at, new Semaphore(5));
		}
		
		for(int i = 0; i < GYM_REGISTERED_CLIENTS; i++){
			executor.execute(new Runnable(){
				public void run(){
			
					try {
						genClient.acquire();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					
					/*int x = (int)(Math.random()*100000);
					while(clients.contains(x))
						x = (int)Math.random();
					*/
					clients.add(count);
					Client temp = Client.generateRandom(count++);
					
					System.out.println("Client "+temp.getId()+" was generated.");
					
					genClient.release();
					
					for(Exercise exercise : temp.getRoutine()){
						while(true){
							try{
								semaAT.get(exercise.at).acquire();
							} catch (InterruptedException e){
								e.printStackTrace();
							}
							//We have acquired the first exercise machine in our routine
							
							System.out.println("Client "+temp.getId()+" has acquired "+exercise.at);
							
							try{
								checkWeights.acquire();
							} catch (InterruptedException e){
								e.printStackTrace();
							}						
							
							//System.out.println("Client "+temp.getId()+" is checking for her weights\n"+exercise.weight);
							
							//We are checking to see if our weights are there
							if(exercise.weight.get(WeightPlateSize.SMALL_3KG) < noOfWeightPlates.get(WeightPlateSize.SMALL_3KG)
									&& exercise.weight.get(WeightPlateSize.MEDIUM_5KG) < noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG)
											&& exercise.weight.get(WeightPlateSize.LARGE_10KG) < noOfWeightPlates.get(WeightPlateSize.LARGE_10KG)){
								//our plates are there, now we try to actually take them
								try{
									putTakeWeights.acquire();
								} catch (InterruptedException e){
									e.printStackTrace();
								}
								//we have access to the rack, now take the plates
								
								System.out.println("Client "+temp.getId()+" has gotten access to the weight rack.");
								/*System.out.println("The current weiht count is as follows:");
								System.out.println(noOfWeightPlates.get(WeightPlateSize.SMALL_3KG));
								System.out.println(noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG));
								System.out.println(noOfWeightPlates.get(WeightPlateSize.LARGE_10KG));
								*/
								noOfWeightPlates.put(WeightPlateSize.SMALL_3KG, 
										noOfWeightPlates.get(WeightPlateSize.SMALL_3KG) - exercise.weight.get(WeightPlateSize.SMALL_3KG));
								noOfWeightPlates.put(WeightPlateSize.MEDIUM_5KG, 
										noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG) - exercise.weight.get(WeightPlateSize.MEDIUM_5KG));
								noOfWeightPlates.put(WeightPlateSize.LARGE_10KG, 
										noOfWeightPlates.get(WeightPlateSize.LARGE_10KG) - exercise.weight.get(WeightPlateSize.LARGE_10KG));
								//release the rack, and the checks
								
								/*System.out.println("The current weight count is:");
								System.out.println(noOfWeightPlates.get(WeightPlateSize.SMALL_3KG));
								System.out.println(noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG));
								System.out.println(noOfWeightPlates.get(WeightPlateSize.LARGE_10KG));
*/
								putTakeWeights.release();
								checkWeights.release();
							}
							else{ //if your weights aren't there, release the machine and the weights
								//release the checks
								checkWeights.release();
								semaAT.get(exercise.at).release();
								try {
									Thread.sleep(exercise.duration);
								} catch (InterruptedException e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								}
								continue;
							}
							//Here, we have the machine, we have our weights on the machine. Time to work out.
							try {
								Thread.sleep(exercise.duration);
								//This is to avoid starvation
							} catch (InterruptedException e) {
								// TODO Auto-generated catch block
								e.printStackTrace();
							}
							
							try{
								putTakeWeights.acquire();
							} catch (InterruptedException e){
								e.printStackTrace();
							}
							// put the plates back
							
							/*System.out.println("Client "+temp.getId()+" is putting her weights back.\n"+exercise.weight);
							
							System.out.println("The current weiht count is as follows:");
							System.out.println(noOfWeightPlates.get(WeightPlateSize.SMALL_3KG));
							System.out.println(noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG));
							System.out.println(noOfWeightPlates.get(WeightPlateSize.LARGE_10KG));
							*/
							noOfWeightPlates.put(WeightPlateSize.SMALL_3KG, 
									noOfWeightPlates.get(WeightPlateSize.SMALL_3KG) + exercise.weight.get(WeightPlateSize.SMALL_3KG));
							noOfWeightPlates.put(WeightPlateSize.MEDIUM_5KG, 
									noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG) + exercise.weight.get(WeightPlateSize.MEDIUM_5KG));
							noOfWeightPlates.put(WeightPlateSize.LARGE_10KG, 
									noOfWeightPlates.get(WeightPlateSize.LARGE_10KG) + exercise.weight.get(WeightPlateSize.LARGE_10KG));
							//release the rack
							/*
							System.out.println("The current weiht count is as follows:");
							System.out.println(noOfWeightPlates.get(WeightPlateSize.SMALL_3KG));
							System.out.println(noOfWeightPlates.get(WeightPlateSize.MEDIUM_5KG));
							System.out.println(noOfWeightPlates.get(WeightPlateSize.LARGE_10KG));
							*/
							System.out.println("Client "+temp.getId()+" releasing weights");
							
							putTakeWeights.release();
							
							//we've worked out, we've put the weights back, now release the machine
							//System.out.println("Client "+temp.getId()+" releasing machine "+exercise.at);
							semaAT.get(exercise.at).release();
							break;
						}
					}
				}
			});
		}
		executor.shutdown();
	}
}