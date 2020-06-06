{-# LANGUAGE LambdaCase #-}

module Main where

import Codec.Picture
import Codec.Picture.Png
import Control.Monad (forM_)
import Debug.Trace
import Path
import System.Directory (canonicalizePath)
import System.Environment (getArgs)

type AbsFile = Path Abs File

data ImageFile = ImageFile
    { path :: AbsFile
    , content :: Image PixelRGBA8
    }

readImageFile :: FilePath -> IO (Either String ImageFile)
readImageFile path = do
    cpath <- canonicalizePath path
    abspath <- parseAbsFile cpath
    eimage <- readImage path
    pure $ eimage >>= \dyn -> Right $ ImageFile
        { path = abspath
        , content = convertRGBA8 dyn
        }

saveImageFile :: ImageFile -> IO ()
saveImageFile file = do
    let outpath = filename $ path file
    let image = ImageRGBA8 $ content file
    putStrLn $ "Saving the gay to " <> show outpath
    ext <- fileExtension outpath
    case ext of
        ".png" -> savePngImage (fromRelFile outpath) image
        ".jpg" -> saveJpgImage 90 (fromRelFile outpath) image
        ".gif" -> either putStrLn id $ saveGifImage (fromRelFile outpath) image
        _      -> putStrLn "Unknown image type!"

makeGay :: Image PixelRGBA8 -> Image PixelRGBA8
makeGay = pixelMap gay
    where
        avg :: Pixel8 -> Pixel8 -> Pixel8 -> Pixel8
        avg r g b = round $ 0.11 * fromIntegral b + 0.59 * fromIntegral g + 0.3 * fromIntegral r
        gay :: PixelRGBA8 -> PixelRGBA8
        gay (PixelRGBA8 r g b a) = let a' = avg r g b in PixelRGBA8 a' a' a' a

averagePixel :: Foldable f => f PixelRGBA8 -> PixelRGBA8
averagePixel ps = PixelRGBA8 ar ag ab aa
    where
        (rs,gs,bs,as) = foldr (\(PixelRGBA8 r g b a) (rs,bs,gs,as) -> (r:rs,b:bs,g:gs,a:as)) ([],[],[],[]) ps
        (ar,ag,ab,aa) = (average rs, average gs, average bs, average as)
        average ns = sum ns `div` fromIntegral (length ns)

makeNGay :: Int -> Image PixelRGBA8 -> Image PixelRGBA8
makeNGay n p = generateImage pixel w h
    where
        w = imageWidth p
        h = imageHeight p
        pixel x y = averagePixel [ pixelAt p x' y' | x' <- [x-n..x+n], y' <- [y-n..y+n], x' >= 0, y' >= 0, x' < w, y' < h]

makeGayFile :: ImageFile -> ImageFile
makeGayFile file = file { content = makeGay $ content file }

makeNGayFile :: Int -> ImageFile -> ImageFile
makeNGayFile n file = file { content = makeNGay n $ content file }

main :: IO ()
main = do
    args <- getArgs
    images <- mapM readImageFile args
    forM_ images $ \case 
        Left err   -> putStrLn "OY VEY!" >> putStrLn err
        Right file -> do
            print $ path file
            saveImageFile $ makeGayFile file