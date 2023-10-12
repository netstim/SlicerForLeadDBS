SlicerForLeadDBS by netstim
================================

Customized version of Slicer used by Lead-DBS.

The app is used by Lead-DBS to do some Slicer-specific processing (for example WarpDrive).

It includes the cli-modules from SlicerNetstim extension and other dependencies to work out-of-the-box from Lead-DBS.

## Build

Follow Slicer developer guidelines for building this app.

## Patch

Given the problems with h5py in linux (see [here](https://discourse.slicer.org/t/slicer-crashes-when-creating-h5-file/19733)), run the following to patch the package.

```bash
cd release
export S4L_LINUX=SlicerForLeadDBS-0.1.0-2023-10-09-linux-amd64
unzip $S4L_LINUX.zip
cp libitkhdf5_cpp.so $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5_cpp-shared-5.3.so
cp libitkhdf5.so $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5-shared-5.3.so
cp libitkhdf5.so.1 $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5-shared-5.3.so.1
cp libitkhdf5_cpp.so.1 $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5_cpp-shared-5.3.so.1
zip -u $S4L_LINUX.zip $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5_cpp-shared-5.3.so
zip -u $S4L_LINUX.zip $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5-shared-5.3.so
zip -u $S4L_LINUX.zip $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5-shared-5.3.so.1
zip -u $S4L_LINUX.zip $S4L_LINUX/lib/SlicerForLeadDBS-5.2/libitkhdf5_cpp-shared-5.3.so.1
rm -fr $S4L_LINUX
```

## Release

Using github cli to create releases:

```bash
gh release create "v231009-beta" release/*.zip
```