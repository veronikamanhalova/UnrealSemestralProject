# Semestral Project – Ball Corridor Game

A small Unreal Engine game made as the final project for my schools Unreal Engine course.
The player controls a white ball through 4 corridors, collects abilities
and uses them to get past obstacles and reach the finish.

## Controls

| W / S | – Move 1 m forward / backward

| A / D | – Rotate 90° counter-clockwise / clockwise

| E | – Activate the owned ability

## Gameplay

- **Levitation** (orange sphere) – lifts the player for a limited time, allowing them to fly over the black obstacle.
- **Time Slowdown** (blue sphere)– slows down the world, but not the player, so the Crusher can be passed.
- **Crusher** (red obstacle) – moves up and down, touching it sends the player back to the start.
- **Finish** (green sphere) – reaching it ends the game and shows the win screen.

## Implementation

The project combines C++ and Blueprints.

**C++**
- `APlayerBall` – player character, step movement and 90° turning using **Enhanced Input**.
- `ABallGameMode` – game mode base class.

**Blueprints**
- `BP_PlayerBall` – player visuals, third-person camera, ability logic, HUD.
- `BP_Ability` – parent ability class, `BP_Levitation` and `BP_Slowdown` are its children.
- `BP_Crusher` – moving obstacle (InterpToMovement) with a reset-to-start trigger.
- `BP_Finish` – finish trigger.
- `E_Ability` – enum of ability types.
- `WBP_HUD` / `WBP_Win` – ability display and win screen.
- `Inputs/` – Input Actions `IA_Move`, `IA_Turn`, `IA_Ability` and mapping context `IMA_Default`.

Implemented using Unreal Engine 5.8.
