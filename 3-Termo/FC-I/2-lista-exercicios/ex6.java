import java.io.File;
class ex6{
    public static void search(String directoryPath, String keyword){
        File dir = new File(directoryPath);
        File[] filesList = dir.listFiles(); 
        if (filesList != null && filesList.length > 0){
            for (File file : filesList) {
                if (file.isFile() && file.getName().contains(keyword)){
                    System.out.println(file.getAbsolutePath());
                } else if (file.isDirectory()){
                    search(file.getAbsolutePath(), keyword);
                }
            }
        } else{
            System.out.println("Nenhum arquivo encontrado na pasta: " + dir.getAbsolutePath());
        }
    }
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Uso correto: java SearchFile <caminho_da_pasta> <palavra-chave>");
            return;
        }
        String directoryPath = args[0];  
        String keyword = args[1];        
        search(directoryPath, keyword);  
    }
}

