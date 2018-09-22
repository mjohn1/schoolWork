import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Main {
    
    public static final String SEPARATOR = "@";
    public static final String COLON = ":";
    public static final String BUY = "BUY";
    public static final String SELL = "SELL";
    
    /*
     * Complete the function below.
     *
 	 * Note: The questions in this test build upon each other. We recommend you
	 * copy your solutions to your text editor of choice before proceeding to
	 * the next question as you will not be able to revisit previous questions.
	 */

     static class Holding implements Comparable<Holding>{
        private String ticker;
        private String name;
        private double quantity = 0;
        private double price = -1;
        private double value = 0;
        private double NAV = 0;
        
        DecimalFormat df = new DecimalFormat("#.00");
                
         public Holding(String t, String n, String q){
             ticker = t;
             name = n;
             quantity = Integer.parseInt(q);
         }
         public Holding(String t, String n, String q, String p){
            ticker = t;
            name = n;
            quantity = Integer.parseInt(q);
            price = Double.parseDouble(p);
            value = (double)quantity*price;
         }
         public void setNAV(double total){
            NAV = (value/total) * 100;
        }
        public double getNAV(){
            return NAV;
        }
        public double getValue(){
            return value;
        }
        public double getPrice(){
            return price;
        }
         public void setTicker(String t){
             ticker = t;
         }
         public String getTicker(){
             return ticker;
         }
         public void setName(String n){
             name = n;
         }
         public String getName(){
             return name;
         }
         public void setQuantity(String i){
             quantity = Double.parseDouble(i);
         }
        public void setQuantity(double d){
            quantity = d;
        }
         public double getQuantity(){
             return quantity;
         }
         public String toString(){
            if (price > -1) {
            return "["+ticker+", "+name+", "+quantity+", "+df.format(price)+", "+df.format(value)+", "+df.format(NAV)+"]";
            }
            return "["+ticker+", "+name+", "+quantity+"]";
         }
        public int compareTo(Holding h){
            return this.getTicker().compareTo(h.getTicker());
        }
     }
    
    static class Transaction{
        private String type;
        private String ticker;
        private double quantity;
        
        DecimalFormat df = new DecimalFormat("#.00");
              
        public Transaction(String tick, double q){
            ticker = tick;
            type = (q < 0) ? SELL : BUY;
            quantity = q;
            
        }
        public String toString(){
             return "["+type+", "+ticker+", "+df.format(quantity)+"]";
        }
        
    }
    
    static class Portfolio{
        // This class is to help with the fifth problem
        // This class would've been helpful the whole time 
        private Holding[] holdings;
        int index = 0;
        private double total;// This is the total value of the portfolio
        DecimalFormat df = new DecimalFormat("#.00");
        
        public Portfolio(int size){
            holdings = new Holding[size];
        }
        public void addHolding(Holding h){
            if (index < holdings.length) {
                holdings[index] = h;
                index++;
            }
            else
                System.out.println("Can't add holding. No more space.");
        }
        public void getTotalValue(){
            double t = 0;
            for (int i = 0; i < holdings.length; i++) {
                t += holdings[i].getValue();
                //System.out.println(holdings[i].getValue());
            }
            //System.out.println(t);
            total = t;
            setNAVforHoldings();
        }
        public double getTotal(){
            return total;
        }
        private void setNAVforHoldings(){
            for (int i = 0; i < holdings.length; i++) {
                holdings[i].setNAV(total);
            }
        }
        public Holding[] getHoldings(){
            return this.holdings;
        }
        public String setAllQs(Portfolio p){
            String ret = "";
            for (int i = 0; i < holdings.length; i++) {
                this.getHoldings()[i].setQuantity(((this.getHoldings()[i].getNAV()/100)*p.getTotal())/p.getHoldings()[i].getPrice());
                ret = ret + stringHelper(this.getHoldings()[i], holdings.length, i);
            }
            return ret;
        }
        private String stringHelper(Holding h, int l, int i){
           String ret = "";
           if (i == l-1)
               ret = ret+ h.getTicker()+", "+h.getName()+", "+df.format(h.getQuantity());
           else
               ret = ret+ h.getTicker()+", "+h.getName()+", "+df.format(h.getQuantity())+ "@";
           return ret;
        }
        public String toString(){
            String ret = "";
            Arrays.sort(holdings);
            for (int i = 0; i < holdings.length; i++) {
                if (i == holdings.length-1)
                    ret = ret+ holdings[i].toString();
                else
                    ret = ret+ holdings[i].toString()+ ", ";
            }
            return ret;
        }
    }

    static int countHoldings(String input) {
        int ret = 1; //this assumes that one portfolio is not followed by an @ symbol
        
        String pattern = "[0-9]"+SEPARATOR+"[A-Z]";
        
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(input);
        //System.out.println(pattern);
                
        while(m.find()){
            ret++;
        }

        return ret;
    }
    
    static String printHoldings(String portfolioString) {
        String ret = "";
        String temp[];
        String items[];
        String split = ",";
        
        items = portfolioString.split(COLON); //splits portfolio from benchmark
        int h = countHoldings(items[1]);
        Holding [] holdings = new Holding[h];        
        items = items[1].split(SEPARATOR); //splits the benchmark to be handled
        
        Arrays.sort(items); 
               
        for(int i = 0; i < h; i++) {
            temp = items[i].split(split);
            holdings[i] = new Holding(temp[0], temp[1], temp[2]);
            if (i+1 == h)
                ret = ret + holdings[i].toString();
            else
                ret = ret + holdings[i].toString() + ", ";
        }
        return ret;
    }
    
    static String originalGenerateTransactions(String input) {
        //Minor tweaks from the original in order to handle double quantities instead of ints
        String ret = ""; //return string
        String temp[]; //array of 2 elems. [portfolio string, benchmark string]
        String portfolio[]; //temp array to hold portfolio holding strings. temp[0]
        String benchmark[]; //temp array to hold deliniated holdings for benchmark. temp[1]
        String split = ",";
        String p[]; //temp array to hold indiv
        String b[];
        
        temp = input.split(COLON);
        portfolio= temp[0].split(SEPARATOR);
        benchmark = temp[1].split(SEPARATOR);
        Arrays.sort(portfolio);
        Arrays.sort(benchmark);
                
        int h = countHoldings(temp[0]);
        Transaction tran[] = new Transaction[h]; // array of transaction objects
        
        for (int i = 0; i < h; i++) {
            p = portfolio[i].split(split); //three elems. [ticker, name, quantity]
            b = benchmark[i].split(split); //three elems. [ticker, name, quantity]
            tran[i] = new Transaction(p[0], Double.parseDouble(b[2])-Double.parseDouble(p[2]));
        }
        for (int i = 0; i < h; i++) {
            if (i+1 == h)
                ret = ret + tran[i].toString();
            else
                ret = ret + tran[i].toString() + ", ";
        }
        return ret;    
    }
    
    static String printHoldingsWithWeight(String inputString) {
        String ret = ""; //return string
        String temp[]; //array of 2 elems. [portfolio string, benchmark string]
        String portfolio[]; //temp array to hold portfolio holding strings. temp[0]
        String benchmark[]; //temp array to hold deliniated holdings for benchmark. temp[1]
        String split = ",";
        String pTemp[]; //temp array to hold indiv
        String bTemp[];
        
        temp = inputString.split(COLON);
        portfolio= temp[0].split(SEPARATOR);
        benchmark = temp[1].split(SEPARATOR);
               
        int h = countHoldings(temp[0]);
        //System.out.println(h);
        Portfolio P = new Portfolio(h);        
                
        for (int i = 0; i < h; i++) {
            pTemp = portfolio[i].split(split);
            bTemp = benchmark[i].split(split);
            P.addHolding(new Holding(pTemp[0], pTemp[1], pTemp[2], bTemp[3]));
        }
        P.getTotalValue(); //This function calculates the total value of the portfolio and sparks each holding to calculate their %NAV
        ret = P.toString();
        return ret;
    }
    static String generateTransactions(String inputString) {
        
        String ret = ""; //return string
        String temp[]; //array of 2 elems. [portfolio string, benchmark string]
        String portfolio[]; //temp array to hold portfolio holding strings. temp[0]
        String benchmark[]; //temp array to hold deliniated holdings for benchmark. temp[1]
        String split = ",";
        String pTemp[]; //temp array to hold indiv
        String bTemp[];
                        
        temp = inputString.split(COLON);
        portfolio= temp[0].split(SEPARATOR);
        benchmark = temp[1].split(SEPARATOR);
                               
        int h = countHoldings(temp[0]);
        //System.out.println(h);
        Portfolio P = new Portfolio(h);
        Portfolio B = new Portfolio(h);       
                                
        for (int i = 0; i < h; i++) {
            pTemp = portfolio[i].split(split);
            bTemp = benchmark[i].split(split);
            P.addHolding(new Holding(pTemp[0], pTemp[1], pTemp[2], bTemp[3]));
            B.addHolding(new Holding(bTemp[0], bTemp[1], bTemp[2], bTemp[3]));
        }
        P.getTotalValue();
        B.getTotalValue();
        
        ret = originalGenerateTransactions(temp[0] + COLON + B.setAllQs(P));
           
        return ret;
    }
                        
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(System.in);
        String ret;
        String _input;
        try {
            _input = in.nextLine();
        } catch (Exception e) {
            _input = null;
        }
        //res = countHoldings(_input);
        ret = generateTransactions(_input);
        System.out.println(ret);
    }
}
