import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;
 
public class Main 
{
private static final char STAR = '*';
private static final int DICT_WORD_MAX_LENGTH = 16;
private static final int NUM_LETTERS = 26;
  
private static List< String > [] indexedDict;
@SuppressWarnings("unchecked")
public static void main( String[] args ) throws IOException{
final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
String line = in.readLine();
int dictLength = Integer.parseInt(line.trim());
          String[] dictionary = new String[dictLength];
          for(int i = 0; i < dictLength; i++){
            line = in.readLine();
            dictionary[i] = line;
          }
         
          // index dictionary words by their length
          // this will make an operation that returns all  dictionary
          // words of some length n run in O(1) time.
       indexedDict = (List< String > []) new ArrayList[DICT_WORD_MAX_LENGTH + 1];
       for(String dictWord : dictionary){
		 int index = dictWord.length();
         if(indexedDict[index] == null)
           indexedDict[index] = new ArrayList< String >();
         indexedDict[index].add(dictWord);
       }
         
          while((line = in.readLine()) != null){
            String[] encryptedWords = line.split(" ");
            if(encryptedWords != null && encryptedWords.length != 0)
         System.out.println(decrypt(encryptedWords));
          }
        }
     
   private static String decrypt(String[] encryptedWords){
     char[] mappings = new char[NUM_LETTERS];
     for(int i = 0; i < mappings.length; i++)
      mappings[i] = STAR;
      
     mappings = backtrack(0, mappings, encryptedWords);
      
     return buildDecryptedString(mappings, encryptedWords);
    }
     
private static String buildDecryptedString(char[] mappings, String[] encryptedWords){
     StringBuilder builder = new StringBuilder();
     for(String word : encryptedWords){
       for(char character : word.toCharArray()){
          if(mappings != null){
      builder.append(mappings[character - 'a']);
          }else{
             builder.append(STAR);
          }
       }
       builder.append(" ");
     }
      
     return builder.toString().trim();
    }
     
private static char[] backtrack(int i, char[] mappings, String[] encryptedWords){
     if(i == encryptedWords.length) // all encrypted words have been successfully decrypted, return final mappings
      return mappings;
     else{
       for(String dictWord : indexedDict[encryptedWords[i].length()]){
         char[] localMappings = Arrays.copyOf(mappings, mappings.length);
            if(mappingPossible(encryptedWords[i], dictWord, localMappings)){
         localMappings = backtrack(i + 1, localMappings, encryptedWords);
         if(localMappings != null)
           return localMappings;
          }
            }
         return null;
     }
    }
     
    /**
     * mappingPossible("abc", "xyz") returns true
     * whereas mappingPossible("iif", "abc") returns false because
     * 'i' will be mapped to both 'a' and 'b'
     */
public static boolean mappingPossible(String encrypted, String plaintext, char[] mappings){
 
     if(encrypted.length() != plaintext.length()) // words must be of the same length
       return false;
      
     char[] encryptedChars = encrypted.toCharArray();
     char[] plaintextChars = plaintext.toCharArray();
      
     // this part makes sure that mapping [all -> the] is false
     for(int i = 0; i < encryptedChars.length; i++){
       char encryptedChar = encryptedChars[i];
          char plaintextChar = plaintextChars[i];
       
       int index = encryptedChar - 'a';
       if(mappings[index] != STAR && mappings[index] != plaintextChar)
         return false; // CONFLICT - this encryptedChar has already been previously mapped to some other plaintextChar        // thus, the proposed [encrypted -> plaintext] mapping is invalid   
           else
         mappings[index] = plaintextChar;
     }
      
     // this part ensures that mapping [the -> all] is false
     return injective(mappings);
    }
     
private static boolean injective(char[] mappings){
     int[] injectiveMappings = new int[NUM_LETTERS];
     for(char mappedChar : mappings){
       if(mappedChar != STAR){
      int index = mappedChar - 'a';
      if(injectiveMappings[index] != 0)
      return false;
      else
      injectiveMappings[index] = 1;
       }
     }
     return true;
    }
}