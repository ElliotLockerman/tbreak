Termbreak Level Pack Documentation
==================================

Background
----------

A Termbreak level pack is a [JSON](http://en.wikipedia.org/wiki/JSON) config file.

The default level pack is loaded up automatically when Termbreak is started. To load a custom level pack, specify the path to the pack as the first argument

It is instructive to examine "level pack example.json", a copy of the default level pack. Feel free to make changes; the original is compiled in.

Properties
----------

### Root-Level Properties

|Key|Value type|Permissible values|Required?|Notes|
|:--|:---------|:-----------------|:--------|:----|
|"starting\_lives"|number|\> 0|Yes|Decrements by one each time the ball hits the bottom. Game ends when lives hits 0|
|"levels"|Array of [level objects](#level_objects)|One or more [level objects](#level_objects)|Yes||

Level Objects
-------------

Each level object represents a single level. They are played in the order written.

Each level must have properties "type" and "name". The type determines which properties a level may/must have, and how the blocks are laid out. The only currently available type is "block\_grid". The name is displayed at the top of each level.

### Generic Properties

|Key|Value type|Permissible values|Required?|Notes|
|:--|:---------|:-----------------|:--------|:----|
|"type"|string|"block\_grid"|Yes||
|"name"|string|1 to 70 (inclusive) characters|Yes|May include a number which does not affect level order.|

### Level type "block\_grid" properties

Levels of type "block\_grid" contain a matrix of identical rectangular blocks

|Key|Value type|Permissible values|Required?|Notes|
|:--|:---------|:-----------------|:--------|:----|
|"block\_width"|number|\> 0|Yes|The width of each block, in number of characters|
|"block\_height"|number|\> 0|Yes|The height of each block, in number of characters|
|"block\_default\_char"|string|\> 0 characters|Yes|The default character written to each character making up the block. If more than one is given, the first is used|
|"block\_string"|string|1 to width\*height (inclusive) characters|No|Overwrites default characters, wrapping at the end|
|"number\_of\_columns"|number|\> 0|Yes||
|"number\_of\_rows"|number|\> 0|Yes||
|"points\_per\_block"|number|\> 0|Yes||
|"starting\_x"|number|\> 0|Yes|x-coordinate of first (top-left) block|
|"starting\_y"|number|\> 0|Yes|y-coordinate of first (top-left) block|
|"top\_margin"|number|\> 0|No|Number of rows of characters between each row of blocks. Default is 0.|
|"left\_margin"|number|\> 0|No|Number of columns of characters between each column of blocks. Default is 0.|