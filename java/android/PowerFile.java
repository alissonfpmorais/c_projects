import java.io.File;

/**
 * Created by Álisson Morais on 10/04/2017.
 */

public class PowerFile extends File {
    // Constructor
    public PowerFile(String fileName) {
        super(fileName);
    }

    public PowerFile(File file) {
        super(file.getName());
    }

    /**
     * Get path where file is located in any folder nested in root path
     * @param rootPath {@link String} of root path where start search
     * @return {@link File} with absolute path to file or null if not found
     */
    public File getLocation(String rootPath) {
        // Call getLocation passing a File as parameter
        return getLocation(new File(rootPath));
    }

    /**
     * Get path where file is located in any folder nested in root path
     * @param rootPath {@link File} of root path where start search
     * @return {@link File} with absolute path to file or null if not found
     */
    public File getLocation(File rootPath) {
        File path = null;

        // Check if rootPath exists
        if(rootPath.exists()) {
            // Get list of files and directories inside root path
            File[] files = rootPath.listFiles();

            // Check if exists files
            if(files != null) {
                // For each file check if path is different of null
                for(int i = 0; (i < files.length) && (path == null); i++) {
                    // If files[i] is a file check for name equals this object
                    // else if files[i] is a directory call getLocation recursively
                    if(files[i].isDirectory()) {
                        path = getLocation(files[i]);
                    } else if(files[i].getName().equals(this.getName())) {
                        path = files[i];
                    }
                }
            }
        }

        return path;
    }
}
