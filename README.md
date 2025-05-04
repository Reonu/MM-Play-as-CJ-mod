# Play as CJ mod for Majora's Mask

![Zelda 64_ Recompiled 04_05_2025 9_22_52](https://github.com/user-attachments/assets/3a3c8dbf-4f58-431d-a279-e29a539b76f8)

This mod lets you play as CJ in Majora's Mask

### Known issues
- CJ's right arm sometimes glitches out in first person.
- GetItem models might not always be aligned correctly.
- The Bunny Hood and Great Fairy Mask are too big.
- CJ is too tall for some cutscenes. The [No Letterboxing Mod](https://thunderstore.io/c/zelda-64-recompiled/p/LT_Schmiddy/No_Letterboxing/) is recommended to alleviate this somewhat.
  - This might be fixed in the future by making CJ crouch in cutscenes when standing still, just like he does now when playing the ocarina.

### Planned updates
- Sound
- Making Big Smoke optional and improving his skinning


### Building
* First, run `make` (with an optional job count) to build the mod code itself.
* Next, run the `RecompModTool` utility with `mod.toml` as the first argument and the build dir (`build` in the case of this template) as the second argument.
  * This will produce your mod's `.nrm` file in the build folder.
  * If you're on MacOS, you may need to specify the path to the `clang` and `ld.lld` binaries using the `CC` and `LD` environment variables, respectively.

### Updating the Majora's Mask Decompilation Submodule
Mods can also be made with newer versions of the Majora's Mask decompilation instead of the commit targeted by this repo's submodule.
To update the commit of the decompilation that you're targeting, follow these steps:
* Build the [N64Recomp](https://github.com/N64Recomp/N64Recomp) repo and copy the N64Recomp executable to the root of this repository.
* Build the version of the Majora's Mask decompilation that you want to update to and copy the resulting .elf file to the root of this repository.
* Update the `mm-decomp` submodule in your clone of this repo to point to the commit you built in the previous step.
* Run `N64Recomp generate_symbols.toml --dump-context`
* Rename `dump.toml` and `data_dump.toml` to `mm.us.rev1.syms.toml` and `mm.us.rev1.datasyms.toml` respectively.
  * Place both files in the `Zelda64RecompSyms` folder.
* Try building.
  * If it succeeds, you're done.
  * If it fails due to a missing header, create an empty header file in the `include/dummy_headers` folder, with the same path.
    * For example, if it complains that `assets/objects/object_cow/object_cow.h` is missing, create an empty `include/dummy_headers/objects/object_cow.h` file.
  * If RecompModTool fails due to a function "being marked as a patch but not existing in the original ROM", it's likely that function you're patching was renamed in the Majora's Mask decompilation.
    * Find the relevant function in the map file for the old decomp commit, then go to that address in the new map file, and update the reference to this function in your code with the new name.
