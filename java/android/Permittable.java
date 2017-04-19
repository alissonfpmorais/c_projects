/**
 * Created by Álisson Morais on 23/03/2017.
 */
public interface Permittable {
    void onPermissionGranted(int requestCode);
    void onPermissionDenied(int requestCode);
}
