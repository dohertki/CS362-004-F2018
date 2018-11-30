/*
 * CS362

 */

import com.sun.tools.javac.util.Assert;

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!



import static org.junit.Assert.*;

public class UrlValidatorTest extends TestCase {


 public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   
	   
   
	   public void testManualTest()
	   {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   String[][] urls = new String[10][2];
		   urls[0][0] = "http://www.google.com";
		   urls[1][0] = "https://www.google.com";
		   urls[2][0] = "ftp://www.google.com";
		   urls[3][0] = "ftps://www.google.com";
		   urls[4][0] = "htp://www.google.com";
		   urls[5][0] = "http:/www.google.com";
		   urls[6][0] = "http://wwwgoogle.com";
		   urls[7][0] = "http://www.google.ca:";
		   urls[8][0] = "//www.google.com";
		   urls[9][0] = "www.google.com";
		   
		   urls[0][1] = "true";
		   urls[1][1] = "true";
		   urls[2][1] = "true";
		   urls[3][1] = "true";
		   urls[4][1] = "true";
		   urls[5][1] = "true";
		   urls[6][1] = "true";
		   urls[7][1] = "false";
		   urls[8][1] = "false";
		   urls[9][1] = "true";

		   
		   for (int i = 0; i < 10; i++) {
			   try {
				   if(urlVal.isValid(urls[i][0]) != Boolean.parseBoolean(urls[i][1])) {
					   System.out.println("Test Failed for: " + urls[i][0]);
				   };
				   
			   } catch(Error e)
			   {
				   System.out.println("Error on: " + urls[i][0] + " " + e);
			   }	   
		   } 
		   
		   
		   
	   }
	   
   
   
   
   
   
   
   
   public void testYourFirstPartition()
   {
	   
	
	   
	   
	   //You can use this function to implement your First Partition testing	   
	   
	   System.out.print("First Partition Test- IP6 \n"); 
	   
	   
	   //Check URLs that consist of literal IP6 addresses. Following are examples from  RFC 2732.
		String [] ipAuth= { "http://[2001:db8::7]/c=GB?objectClass?one",
							"http://[FEDC:BA98:7654:3210:FEDC:BA98:7654:3210]:80/index.htm",
							"http://[1080:0:0:0:8:800:200C:417A]/index.html",
				            "http://[3ffe:2a00:100:7031::1]",
				            "http://[1080::8:800:200C:417A]/foo",
				            "http://[::192.9.5.5]/ipng",
				            "http://[::FFFF:129.144.52.38]:80/index.html",
				            "http://[2010:836B:4179::836B:4179]"		
		};
	   
		// Reserved characters are not used in IP6 address.
		char [] reserv = { ';', '?', '@', '&', '=', '=', '$',','};
		
	   
	   // UrlValidator urlVal = new UrlValidator();
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   for(String el: ipAuth) {
		   try{
			   assertEquals(true, urlVal.isValid( el ));
		          System.out.println(". PASSED: " + el );
		     }catch(AssertionError e){
		          System.out.println( "# FAILED: " + el );
		      
		     }
		}
		
	   //Replace the characters in an IP6 address with reserved characters, isValid should
	   //return with a fail value.
	   for(char ch: reserv) {
		
	
		   try{
			   assertEquals(false, urlVal.isValid( ipAuth[0].replace( '2', ch) ));
		          System.out.println(". PASSED: " + ipAuth[0].replace( '2', ch));
		     }catch(AssertionError e){
		          System.out.println( "# FAILED: " + ipAuth[0].replace( '2', ch) );
		      
		     }
		}
	   

	   
   }
     
	
  
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   
	   
	  fail();
	   

	   
   }
     
	   
	   
	   
	   

   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   fail();
	   //You can use this function for programming based testing

   }
   




}






