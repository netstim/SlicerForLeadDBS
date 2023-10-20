SlicerForLeadDBS by netstim
================================

Customized version of Slicer used by Lead-DBS.

The app is used by Lead-DBS to do some Slicer-specific processing (for example WarpDrive).

It includes the cli-modules from SlicerNetstim extension and other dependencies to work out-of-the-box from Lead-DBS.

## Build

Follow Slicer developer guidelines for building this app.

## Patch

Still some issues when fixing h5py rpath. To do this manually:

```bash
cd ZIP
for x in SlicerForLeadDBS-0.1.0-2023-10-13-macosx-amd64/SlicerForLeadDBS.app/Contents/lib/Python/lib/python3.9/site-packages/h5py/*.so; do install_name_tool -change  @rpath/libhdf5_hl.200.dylib @rpath/lib/SlicerForLeadDBS-5.4/libhdf5_hl.200.dylib $x; done
for x in SlicerForLeadDBS-0.1.0-2023-10-13-macosx-amd64/SlicerForLeadDBS.app/Contents/lib/Python/lib/python3.9/site-packages/h5py/*.so; do install_name_tool -change  @rpath/libhdf5.200.dylib @rpath/lib/SlicerForLeadDBS-5.4/libhdf5.200.dylib $x; done
zip -r SlicerForLeadDBS-0.1.0-2023-10-13-macosx-amd64.zip SlicerForLeadDBS-0.1.0-2023-10-13-macosx-amd64
```

## Release

Using github cli to create releases:

```bash
gh release create "v231009-beta" release/*.zip
```