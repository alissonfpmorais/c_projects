package br.com.dl.dlmanual.utils;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;

/**
 * Created by Álisson Morais on 23/03/2017.
 */

public class Permission implements ActivityCompat.OnRequestPermissionsResultCallback {
    /**
     * Store the object that requested permission
     */
    private Executable executable;

    /**
     * Permission ID for permission result
     */
    private int requestCode;

    // Constructor
    public Permission(Executable executable) {
        this.executable = executable;
    }

    /**
     * In case that permission are granted, execute permissonGranted of {@link Executable}.
     * Case not, it request user permission.
     * @param activity Activity that requested the permission
     * @param permissionName The permission that are asked. Pass {@link Manifest} permissions
     * @param requestCode Id of requested permission
     */
    public void executeWithPermissions(Activity activity, String permissionName, int requestCode) {
        // Check if permission are available
        if (ContextCompat.checkSelfPermission(activity, permissionName) !=
                PackageManager.PERMISSION_GRANTED) {

            // Set requestCode
            this.requestCode = requestCode;

            // Request permission
            ActivityCompat.requestPermissions(activity,
                    new String[]{ permissionName }, this.requestCode);
        } else {
            // Execute onPermissionGranted from the requester
            executable.onPermissionGranted(requestCode);
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           @NonNull String permissions[],
                                           @NonNull int[] grantResults) {

        // Check requestCode against requestCode
        if(requestCode == this.requestCode) {
            // Check if permisison is granted
            if (grantResults.length > 0
                    && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                // Execute onPermissionGranted from the requester
                executable.onPermissionGranted(requestCode);
            } else {
                // Execute onPermissionDenied from the requester
                executable.onPermissionDenied(requestCode);
            }
        }
    }
}
