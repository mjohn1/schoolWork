import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Holding{
        private String ticker;
        private String name;
        private int quantity;
        
        public Holding(String t, String n, String q){
            ticker = t;
            name = n;
            quantity = Integer.parseInt(q);
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
            quantity = Integer.parseInt(i);
        }
        public int getQuantity(){
            return quantity;
        }
        public String toString(){
            return "["+ticker+", "+name+", "+quantity+"]";
        }
    }
