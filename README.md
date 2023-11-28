SlicerForLeadDBS by netstim
================================

Customized version of Slicer used by Lead-DBS.

The app is used by Lead-DBS to do some Slicer-specific processing (for example WarpDrive).

It includes the cli-modules from SlicerNetstim extension and other dependencies to work out-of-the-box from Lead-DBS.

## Build

Follow Slicer developer guidelines to build this app.

### Known errors

For some reason local build fails in Windows beacuse of a problem in LibFFI project. Solution is to build the project in Debug configuration; copy the `debug.obj` from `C:\S4L\LibFFI-build\objlib.dir\Debug` to `C:\S4L\LibFFI-build\objlib.dir\Release`; and build again in Release configuration

## Package

Follow Slicer developer guidelines to package this app.

### Known errors

Still some issues when fixing h5py rpath in macos. Manuall solution:

```bash
cd ZIP
for x in SlicerForLeadDBS-0.1.0-2023-11-22-macosx-amd64/SlicerForLeadDBS.app/Contents/lib/Python/lib/python3.9/site-packages/h5py/*.so; do install_name_tool -change  @rpath/libhdf5_hl.200.dylib @rpath/lib/SlicerForLeadDBS-5.2/libhdf5_hl.200.dylib $x; done
for x in SlicerForLeadDBS-0.1.0-2023-11-22-macosx-amd64/SlicerForLeadDBS.app/Contents/lib/Python/lib/python3.9/site-packages/h5py/*.so; do install_name_tool -change  @rpath/libhdf5.200.dylib @rpath/lib/SlicerForLeadDBS-5.2/libhdf5.200.dylib $x; done
zip -r SlicerForLeadDBS-0.1.0-2023-11-22-macosx-amd64.zip SlicerForLeadDBS-0.1.0-2023-11-22-macosx-amd64
```

## Release

Using github cli to create releases:

```bash
gh release create "v231122-beta" release/*.zip
```