/**
 * Created by Álisson Morais on 23/03/2017.
 */
public interface Executable {
    void onPermissionGranted(int requestCode);
    void onPermissionDenied(int requestCode);
}
