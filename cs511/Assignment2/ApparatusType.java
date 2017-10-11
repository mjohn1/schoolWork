
public enum ApparatusType {
	LEGPRESSMACHINE,
	BARBELL,
	HACKSQUATMACHINE,
	LEGEXTENSIONMACHINE,
	LEGCURLMACHINE,
	LATPULLDOWNMACHINE,
	PECDECKMACHINE,
	CABLECROSSOVERMACHINE;
	
	public static ApparatusType getRandom() {
		return values()[(int) (Math.random() * values().length)];
	}
}